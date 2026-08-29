#include "MotionTrajectory.h"

#include <algorithm>
#include <cmath>

namespace motion {

void MotionTrajectory::set_points(std::vector<TrajectoryPoint> points) { points_ = std::move(points); }
const std::vector<TrajectoryPoint> &MotionTrajectory::points() const { return points_; }

void MotionTrajectory::smooth(float position_alpha, float velocity_alpha) {
    position_alpha = std::clamp(position_alpha, 0.0f, 1.0f);
    velocity_alpha = std::clamp(velocity_alpha, 0.0f, 1.0f);
    for (std::size_t i = 1; i < points_.size(); ++i) {
        points_[i].position = points_[i - 1].position * (1.0f - position_alpha) + points_[i].position * position_alpha;
        points_[i].velocity = points_[i - 1].velocity * (1.0f - velocity_alpha) + points_[i].velocity * velocity_alpha;
    }
}

void MotionTrajectory::constrain_speed(float max_speed) {
    const float max_speed_sq = std::max(0.0f, max_speed) * std::max(0.0f, max_speed);
    for (TrajectoryPoint &point : points_) {
        const float speed_sq = point.velocity.length_squared();
        if (speed_sq > max_speed_sq && speed_sq > 0.0f) {
            point.velocity = point.velocity * (std::sqrt(max_speed_sq / speed_sq));
        }
    }
}

bool MotionTrajectory::supports_environment(const MotionEnvironmentContext &environment,
                                            const TraversalCapability &capability) const {
    if (!environment.valid) return true;
    if (!environment.blocked) return true;
    if (environment.obstacle_height < capability.min_obstacle_height || environment.obstacle_height > capability.max_obstacle_height) return false;
    if (environment.clearance < capability.required_clearance) return false;
    if (!points_.empty()) {
        const float entry_speed_sq = points_.front().velocity.length_squared();
        if (entry_speed_sq < capability.min_entry_speed * capability.min_entry_speed || entry_speed_sq > capability.max_entry_speed * capability.max_entry_speed) return false;
    }
    return true;
}

bool MotionTrajectory::refine_for_environment(const MotionEnvironmentContext &environment,
                                              const TraversalCapability &capability) {
    if (!supports_environment(environment, capability)) return false;
    if (!environment.valid || points_.empty()) return true;
    for (TrajectoryPoint &point : points_) {
        point.position.y = std::max(point.position.y, environment.ground_height);
    }
    if (environment.blocked && capability.landing_distance > 0.0f) {
        const float max_distance = environment.obstacle_distance + capability.landing_distance + capability.max_warp_translation;
        for (TrajectoryPoint &point : points_) {
            point.position.x = std::min(point.position.x, max_distance);
        }
    }
    return true;
}

} // namespace motion

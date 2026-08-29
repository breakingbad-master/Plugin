#pragma once

#include "../Core/MMCore.h"

#include <cstddef>
#include <vector>

namespace motion {

struct TraversalCapability {
    float min_obstacle_height = 0.0f;
    float max_obstacle_height = 0.0f;
    float min_entry_speed = 0.0f;
    float max_entry_speed = 1000.0f;
    float required_clearance = 0.0f;
    float landing_distance = 0.0f;
    float max_warp_translation = 0.0f;
    float max_warp_rotation = 0.0f;
};

class MotionTrajectory {
public:
    void set_points(std::vector<TrajectoryPoint> points);
    const std::vector<TrajectoryPoint> &points() const;
    void smooth(float position_alpha, float velocity_alpha);
    void constrain_speed(float max_speed);
    bool supports_environment(const MotionEnvironmentContext &environment,
                              const TraversalCapability &capability) const;
    bool refine_for_environment(const MotionEnvironmentContext &environment,
                                const TraversalCapability &capability);

private:
    std::vector<TrajectoryPoint> points_;
};

} // namespace motion

#include "PoseTrajectoryFeature.h"

#include <algorithm>
#include <cmath>

namespace motion {

std::vector<float> PoseTrajectoryFeature::encode(const std::vector<TrajectoryPoint> &trajectory,
                                                 float position_weight, float velocity_weight,
                                                 float yaw_weight) {
    const auto safe_weight = [](float value) {
        return std::isfinite(value) ? std::max(0.0f, value) : 0.0f;
    };
    const float position_scale = safe_weight(position_weight);
    const float velocity_scale = safe_weight(velocity_weight);
    const float yaw_scale = safe_weight(yaw_weight);
    std::vector<float> encoded;
    encoded.reserve(trajectory.size() * 7);
    for (const TrajectoryPoint &point : trajectory) {
        encoded.push_back(point.position.x * position_scale);
        encoded.push_back(point.position.y * position_scale);
        encoded.push_back(point.position.z * position_scale);
        encoded.push_back(point.velocity.x * velocity_scale);
        encoded.push_back(point.velocity.y * velocity_scale);
        encoded.push_back(point.velocity.z * velocity_scale);
        const float yaw = std::isfinite(point.facing_yaw) ? point.facing_yaw : 0.0f;
        encoded.push_back(yaw * yaw_scale);
    }
    return encoded;
}

const ModuleDescriptor &module_posetrajectoryfeature() {
    static const ModuleDescriptor descriptor{
        "PoseTrajectoryFeature", "Weighted future trajectory position, velocity, and facing encoding."};
    return descriptor;
}

} // namespace motion

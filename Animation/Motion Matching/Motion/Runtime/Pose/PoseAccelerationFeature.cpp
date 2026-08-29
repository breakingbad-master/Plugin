#include "PoseAccelerationFeature.h"

#include <algorithm>
#include <cmath>

namespace motion {

std::vector<Vec3> PoseAccelerationFeature::derive(const std::vector<Vec3> &previous_velocity,
                                                  const std::vector<Vec3> &current_velocity,
                                                  float delta_seconds) {
    const std::size_t count = std::min(previous_velocity.size(), current_velocity.size());
    std::vector<Vec3> accelerations(count);
    if (!std::isfinite(delta_seconds) || delta_seconds <= 0.000001f) return accelerations;
    const float inverse_delta = 1.0f / delta_seconds;
    for (std::size_t i = 0; i < count; ++i) accelerations[i] = (current_velocity[i] - previous_velocity[i]) * inverse_delta;
    return accelerations;
}

std::vector<float> PoseAccelerationFeature::flatten(const std::vector<Vec3> &accelerations, float weight) {
    const float safe_weight = std::isfinite(weight) ? std::max(0.0f, weight) : 0.0f;
    std::vector<float> flattened;
    flattened.reserve(accelerations.size() * 3);
    for (const Vec3 &acceleration : accelerations) {
        flattened.push_back(acceleration.x * safe_weight);
        flattened.push_back(acceleration.y * safe_weight);
        flattened.push_back(acceleration.z * safe_weight);
    }
    return flattened;
}

const ModuleDescriptor &module_poseaccelerationfeature() {
    static const ModuleDescriptor descriptor{
        "PoseAccelerationFeature", "Finite-difference bone acceleration encoding for impact matching."};
    return descriptor;
}

} // namespace motion

#include "PoseVelocityFeature.h"

#include <algorithm>
#include <cmath>

namespace motion {

std::vector<Vec3> PoseVelocityFeature::derive(const std::vector<Vec3> &previous,
                                              const std::vector<Vec3> &current, float delta_seconds) {
    const std::size_t count = std::min(previous.size(), current.size());
    std::vector<Vec3> velocities(count);
    if (!std::isfinite(delta_seconds) || delta_seconds <= 0.000001f) return velocities;
    const float inverse_delta = 1.0f / delta_seconds;
    for (std::size_t i = 0; i < count; ++i) velocities[i] = (current[i] - previous[i]) * inverse_delta;
    return velocities;
}

std::vector<float> PoseVelocityFeature::flatten(const std::vector<Vec3> &velocities, float weight) {
    const float safe_weight = std::isfinite(weight) ? std::max(0.0f, weight) : 0.0f;
    std::vector<float> flattened;
    flattened.reserve(velocities.size() * 3);
    for (const Vec3 &velocity : velocities) {
        flattened.push_back(velocity.x * safe_weight);
        flattened.push_back(velocity.y * safe_weight);
        flattened.push_back(velocity.z * safe_weight);
    }
    return flattened;
}

const ModuleDescriptor &module_posevelocityfeature() {
    static const ModuleDescriptor descriptor{
        "PoseVelocityFeature", "Finite-difference bone velocity encoding for motion continuity."};
    return descriptor;
}

} // namespace motion

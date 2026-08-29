#include "PoseAngularVelocityFeature.h"

#include <algorithm>
#include <cmath>

namespace motion {
namespace {
float wrap_angle(float angle) {
    constexpr float pi = 3.14159265358979323846f;
    constexpr float two_pi = 2.0f * pi;
    while (angle > pi) angle -= two_pi;
    while (angle < -pi) angle += two_pi;
    return angle;
}
}

std::vector<PoseEulerAngles> PoseAngularVelocityFeature::derive(const std::vector<PoseEulerAngles> &previous,
                                                                const std::vector<PoseEulerAngles> &current,
                                                                float delta_seconds) {
    const std::size_t count = std::min(previous.size(), current.size());
    std::vector<PoseEulerAngles> velocities(count);
    if (!std::isfinite(delta_seconds) || delta_seconds <= 0.000001f) return velocities;
    const float inverse_delta = 1.0f / delta_seconds;
    for (std::size_t i = 0; i < count; ++i) {
        velocities[i].pitch = wrap_angle(current[i].pitch - previous[i].pitch) * inverse_delta;
        velocities[i].yaw = wrap_angle(current[i].yaw - previous[i].yaw) * inverse_delta;
        velocities[i].roll = wrap_angle(current[i].roll - previous[i].roll) * inverse_delta;
    }
    return velocities;
}

std::vector<float> PoseAngularVelocityFeature::flatten(const std::vector<PoseEulerAngles> &velocities, float weight) {
    const float safe_weight = std::isfinite(weight) ? std::max(0.0f, weight) : 0.0f;
    std::vector<float> flattened;
    flattened.reserve(velocities.size() * 3);
    for (const PoseEulerAngles &velocity : velocities) {
        flattened.push_back(velocity.pitch * safe_weight);
        flattened.push_back(velocity.yaw * safe_weight);
        flattened.push_back(velocity.roll * safe_weight);
    }
    return flattened;
}

const ModuleDescriptor &module_poseangularvelocityfeature() {
    static const ModuleDescriptor descriptor{
        "PoseAngularVelocityFeature", "Wrapped Euler angular velocity encoding for rotational continuity."};
    return descriptor;
}

} // namespace motion

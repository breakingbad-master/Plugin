#include "PosePhaseFeature.h"

#include <cmath>

namespace motion {

float PosePhaseFeature::normalize(float phase) {
    if (!std::isfinite(phase)) return 0.0f;
    phase -= std::floor(phase);
    return phase < 0.0f ? phase + 1.0f : phase;
}

float PosePhaseFeature::delta(float from, float to) {
    const float wrapped_from = normalize(from);
    const float wrapped_to = normalize(to);
    float difference = wrapped_to - wrapped_from;
    if (difference > 0.5f) difference -= 1.0f;
    if (difference < -0.5f) difference += 1.0f;
    return difference;
}

std::array<float, 2> PosePhaseFeature::encode(float phase) {
    constexpr float two_pi = 6.28318530717958647692f;
    const float angle = normalize(phase) * two_pi;
    return {std::cos(angle), std::sin(angle)};
}

const ModuleDescriptor &module_posephasefeature() {
    static const ModuleDescriptor descriptor{
        "PosePhaseFeature", "Wrap-safe cyclic phase and sine/cosine encoding for repeated motion."};
    return descriptor;
}

} // namespace motion

#include "PoseContactFeature.h"

#include <algorithm>
#include <cmath>

namespace motion {

std::vector<float> PoseContactFeature::encode(const std::vector<PoseContactSample> &samples,
                                              float height_threshold, float speed_threshold) {
    const float safe_height = std::isfinite(height_threshold) ? std::max(0.0f, height_threshold) : 0.08f;
    const float safe_speed = std::isfinite(speed_threshold) ? std::max(0.0f, speed_threshold) : 0.15f;
    std::vector<float> encoded;
    encoded.reserve(samples.size() * 2);
    for (const PoseContactSample &sample : samples) {
        const float speed_squared = sample.velocity.length_squared();
        const bool finite_input = std::isfinite(sample.height_above_ground) && std::isfinite(speed_squared);
        const bool in_contact = finite_input && sample.height_above_ground <= safe_height &&
            speed_squared <= safe_speed * safe_speed;
        const float confidence = std::isfinite(sample.confidence)
            ? std::clamp(sample.confidence, 0.0f, 1.0f) : 0.0f;
        encoded.push_back(in_contact ? 1.0f : 0.0f);
        encoded.push_back(in_contact ? confidence : 0.0f);
    }
    return encoded;
}

const ModuleDescriptor &module_posecontactfeature() {
    static const ModuleDescriptor descriptor{
        "PoseContactFeature", "Thresholded contact state and confidence encoding for grounded limbs."};
    return descriptor;
}

} // namespace motion

#include "PoseRootFeature.h"

#include <algorithm>
#include <cmath>

namespace motion {

std::vector<float> PoseRootFeature::encode(const std::vector<PoseRootSample> &samples) {
    std::vector<float> encoded;
    encoded.reserve(samples.size() * 7);
    for (const PoseRootSample &sample : samples) {
        const float weight = std::isfinite(sample.weight) ? std::max(0.0f, sample.weight) : 0.0f;
        const float yaw = std::isfinite(sample.facing_yaw) ? sample.facing_yaw : 0.0f;
        encoded.push_back(sample.position.x * weight);
        encoded.push_back(sample.position.y * weight);
        encoded.push_back(sample.position.z * weight);
        encoded.push_back(sample.velocity.x * weight);
        encoded.push_back(sample.velocity.y * weight);
        encoded.push_back(sample.velocity.z * weight);
        encoded.push_back(yaw * weight);
    }
    return encoded;
}

const ModuleDescriptor &module_poserootfeature() {
    static const ModuleDescriptor descriptor{
        "PoseRootFeature", "Weighted root position, velocity, and facing-yaw encoding."};
    return descriptor;
}

} // namespace motion

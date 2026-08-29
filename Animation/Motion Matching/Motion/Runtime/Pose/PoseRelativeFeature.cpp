#include "PoseRelativeFeature.h"

#include <algorithm>
#include <cmath>

namespace motion {

std::vector<float> PoseRelativeFeature::encode(const std::vector<PoseRelativePair> &pairs) {
    std::vector<float> encoded;
    encoded.reserve(pairs.size() * 3);
    for (const PoseRelativePair &pair : pairs) {
        const float weight = std::isfinite(pair.weight) ? std::max(0.0f, pair.weight) : 0.0f;
        const Vec3 relative = (pair.target - pair.source) * weight;
        encoded.push_back(relative.x);
        encoded.push_back(relative.y);
        encoded.push_back(relative.z);
    }
    return encoded;
}

const ModuleDescriptor &module_poserelativefeature() {
    static const ModuleDescriptor descriptor{
        "PoseRelativeFeature", "Weighted relative-position encoding between important bone pairs."};
    return descriptor;
}

} // namespace motion

#include "PoseBoneFeature.h"

#include <algorithm>
#include <cmath>

namespace motion {

std::vector<float> PoseBoneFeature::encode(const std::vector<PoseBoneTransform> &bones) {
    std::vector<float> encoded;
    encoded.reserve(bones.size() * 6);
    for (const PoseBoneTransform &bone : bones) {
        const float weight = std::isfinite(bone.weight) ? std::max(0.0f, bone.weight) : 0.0f;
        Vec3 forward = bone.forward;
        const float length_squared = forward.length_squared();
        if (length_squared > 0.000001f && std::isfinite(length_squared)) {
            const float inverse_length = 1.0f / std::sqrt(length_squared);
            forward = forward * inverse_length;
        } else {
            forward = {0.0f, 0.0f, 1.0f};
        }
        encoded.push_back(bone.position.x * weight);
        encoded.push_back(bone.position.y * weight);
        encoded.push_back(bone.position.z * weight);
        encoded.push_back(forward.x * weight);
        encoded.push_back(forward.y * weight);
        encoded.push_back(forward.z * weight);
    }
    return encoded;
}

const ModuleDescriptor &module_posebonefeature() {
    static const ModuleDescriptor descriptor{
        "PoseBoneFeature", "Weighted compact bone position and normalized forward-direction encoding."};
    return descriptor;
}

} // namespace motion

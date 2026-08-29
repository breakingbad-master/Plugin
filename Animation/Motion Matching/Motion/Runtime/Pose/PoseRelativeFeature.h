#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <vector>

namespace motion {

struct PoseRelativePair {
    Vec3 source;
    Vec3 target;
    float weight = 1.0f;
};

class PoseRelativeFeature {
public:
    static std::vector<float> encode(const std::vector<PoseRelativePair> &pairs);
};

const ModuleDescriptor &module_poserelativefeature();

} // namespace motion

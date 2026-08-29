#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <vector>

namespace motion {

struct PoseBoneTransform {
    Vec3 position;
    Vec3 forward{0.0f, 0.0f, 1.0f};
    float weight = 1.0f;
};

class PoseBoneFeature {
public:
    static std::vector<float> encode(const std::vector<PoseBoneTransform> &bones);
};

const ModuleDescriptor &module_posebonefeature();

} // namespace motion

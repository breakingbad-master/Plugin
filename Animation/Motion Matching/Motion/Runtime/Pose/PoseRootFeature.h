#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <vector>

struct PoseRootSample {
    motion::Vec3 position;
    motion::Vec3 velocity;
    float facing_yaw = 0.0f;
    float weight = 1.0f;
};

namespace motion {

class PoseRootFeature {
public:
    static std::vector<float> encode(const std::vector<PoseRootSample> &samples);
};

const ModuleDescriptor &module_poserootfeature();

} // namespace motion

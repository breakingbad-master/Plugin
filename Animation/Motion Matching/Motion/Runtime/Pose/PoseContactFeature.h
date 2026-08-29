#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <vector>

namespace motion {

struct PoseContactSample {
    Vec3 position;
    Vec3 velocity;
    float height_above_ground = 0.0f;
    float confidence = 1.0f;
};

class PoseContactFeature {
public:
    static std::vector<float> encode(const std::vector<PoseContactSample> &samples,
                                     float height_threshold = 0.08f, float speed_threshold = 0.15f);
};

const ModuleDescriptor &module_posecontactfeature();

} // namespace motion

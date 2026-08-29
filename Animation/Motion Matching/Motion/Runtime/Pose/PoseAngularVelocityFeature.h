#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <vector>

namespace motion {

struct PoseEulerAngles {
    float pitch = 0.0f;
    float yaw = 0.0f;
    float roll = 0.0f;
};

class PoseAngularVelocityFeature {
public:
    static std::vector<PoseEulerAngles> derive(const std::vector<PoseEulerAngles> &previous,
                                               const std::vector<PoseEulerAngles> &current,
                                               float delta_seconds);
    static std::vector<float> flatten(const std::vector<PoseEulerAngles> &velocities, float weight = 1.0f);
};

const ModuleDescriptor &module_poseangularvelocityfeature();

} // namespace motion

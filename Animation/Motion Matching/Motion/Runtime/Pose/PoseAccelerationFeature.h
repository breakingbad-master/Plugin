#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <vector>

namespace motion {

class PoseAccelerationFeature {
public:
    static std::vector<Vec3> derive(const std::vector<Vec3> &previous_velocity,
                                    const std::vector<Vec3> &current_velocity,
                                    float delta_seconds);
    static std::vector<float> flatten(const std::vector<Vec3> &accelerations, float weight = 1.0f);
};

const ModuleDescriptor &module_poseaccelerationfeature();

} // namespace motion

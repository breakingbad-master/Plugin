#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <vector>

namespace motion {

class PoseVelocityFeature {
public:
    static std::vector<Vec3> derive(const std::vector<Vec3> &previous,
                                    const std::vector<Vec3> &current, float delta_seconds);
    static std::vector<float> flatten(const std::vector<Vec3> &velocities, float weight = 1.0f);
};

const ModuleDescriptor &module_posevelocityfeature();

} // namespace motion

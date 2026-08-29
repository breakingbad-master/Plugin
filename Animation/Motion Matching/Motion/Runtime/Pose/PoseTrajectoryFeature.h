#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <vector>

namespace motion {

class PoseTrajectoryFeature {
public:
    static std::vector<float> encode(const std::vector<TrajectoryPoint> &trajectory,
                                     float position_weight = 1.0f, float velocity_weight = 1.0f,
                                     float yaw_weight = 1.0f);
};

const ModuleDescriptor &module_posetrajectoryfeature();

} // namespace motion

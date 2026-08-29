#pragma once

#include "../Core/MMModule.h"

#include <vector>

namespace motion {

class PoseDistanceMetric {
public:
    static float squared_distance(const std::vector<float> &query,
                                  const std::vector<float> &candidate,
                                  const std::vector<float> &weights = {});
};

const ModuleDescriptor &module_posedistancemetric();

} // namespace motion

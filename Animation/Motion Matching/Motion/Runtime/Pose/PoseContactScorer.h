#pragma once

#include "../Core/MMModule.h"

#include <vector>

namespace motion {

class PoseContactScorer {
public:
    static float score(const std::vector<float> &query, const std::vector<float> &candidate,
                       float state_weight = 1.0f, float confidence_weight = 1.0f);
};

const ModuleDescriptor &module_posecontactscorer();

} // namespace motion

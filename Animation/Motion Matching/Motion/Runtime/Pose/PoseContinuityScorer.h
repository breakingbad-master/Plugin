#pragma once

#include "../Core/MMModule.h"

#include <vector>

namespace motion {

class PoseContinuityScorer {
public:
    static float score(const std::vector<float> &previous, const std::vector<float> &next,
                       float weight = 1.0f);
};

const ModuleDescriptor &module_posecontinuityscorer();

} // namespace motion

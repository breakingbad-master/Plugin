#pragma once

#include "../Core/MMModule.h"

namespace motion {

class PosePhaseScorer {
public:
    static float score(float query_phase, float candidate_phase, float weight = 1.0f);
};

const ModuleDescriptor &module_posephasescorer();

} // namespace motion

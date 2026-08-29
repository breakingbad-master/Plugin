#pragma once

#include "../Core/MMModule.h"

#include <array>

namespace motion {

class PosePhaseFeature {
public:
    static float normalize(float phase);
    static float delta(float from, float to);
    static std::array<float, 2> encode(float phase);
};

const ModuleDescriptor &module_posephasefeature();

} // namespace motion

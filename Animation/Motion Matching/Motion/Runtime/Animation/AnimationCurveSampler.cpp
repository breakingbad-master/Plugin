#include "AnimationCurveSampler.h"

namespace motion {
const ModuleDescriptor &module_animationcurvesampler() {
    static const ModuleDescriptor descriptor{"AnimationCurveSampler", "Samples curves efficiently."};
    return descriptor;
}
} // namespace motion

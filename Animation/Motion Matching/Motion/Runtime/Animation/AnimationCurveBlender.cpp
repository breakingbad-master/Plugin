#include "AnimationCurveBlender.h"

namespace motion {
const ModuleDescriptor &module_animationcurveblender() {
    static const ModuleDescriptor descriptor{"AnimationCurveBlender", "Blends multiple curves."};
    return descriptor;
}
} // namespace motion

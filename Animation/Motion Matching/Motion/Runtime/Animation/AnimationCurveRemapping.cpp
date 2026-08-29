#include "AnimationCurveRemapping.h"

namespace motion {
const ModuleDescriptor &module_animationcurveremapping() {
    static const ModuleDescriptor descriptor{"AnimationCurveRemapping", "Maps source curve ranges to destination ranges."};
    return descriptor;
}
} // namespace motion

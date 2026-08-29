#include "AnimationCurve.h"

namespace motion {
const ModuleDescriptor &module_animationcurve() {
    static const ModuleDescriptor descriptor{"AnimationCurve", "Generic animation curve representation."};
    return descriptor;
}
} // namespace motion

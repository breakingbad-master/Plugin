#include "AnimationCurveDebug.h"

namespace motion {
const ModuleDescriptor &module_animationcurvedebug() {
    static const ModuleDescriptor descriptor{"AnimationCurveDebug", "Curve inspection and visualization."};
    return descriptor;
}
} // namespace motion

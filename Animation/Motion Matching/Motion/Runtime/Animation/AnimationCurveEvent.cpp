#include "AnimationCurveEvent.h"

namespace motion {
const ModuleDescriptor &module_animationcurveevent() {
    static const ModuleDescriptor descriptor{"AnimationCurveEvent", "Curve-driven event markers."};
    return descriptor;
}
} // namespace motion

#include "AnimationCurveProfile.h"

namespace motion {
const ModuleDescriptor &module_animationcurveprofile() {
    static const ModuleDescriptor descriptor{"AnimationCurveProfile", "Reusable curve settings."};
    return descriptor;
}
} // namespace motion

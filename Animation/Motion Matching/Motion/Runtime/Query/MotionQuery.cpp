#include "MotionQuery.h"

namespace motion {
const ModuleDescriptor &module_motionquery() {
    static const ModuleDescriptor descriptor{"MotionQuery", "Base query representation that can describe any animation intent, not locomotion only."};
    return descriptor;
}
} // namespace motion

#include "MotionWarpingTarget.h"

namespace motion {
const ModuleDescriptor &module_motionwarpingtarget() {
    static const ModuleDescriptor descriptor{"MotionWarpingTarget", "Describes a target transform for an animation."};
    return descriptor;
}
} // namespace motion

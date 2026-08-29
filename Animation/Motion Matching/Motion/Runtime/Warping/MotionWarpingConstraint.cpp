#include "MotionWarpingConstraint.h"

namespace motion {
const ModuleDescriptor &module_motionwarpingconstraint() {
    static const ModuleDescriptor descriptor{"MotionWarpingConstraint", "Limits warp magnitude and axis behavior."};
    return descriptor;
}
} // namespace motion

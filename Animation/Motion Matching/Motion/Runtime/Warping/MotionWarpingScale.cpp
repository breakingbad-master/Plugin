#include "MotionWarpingScale.h"

namespace motion {
const ModuleDescriptor &module_motionwarpingscale() {
    static const ModuleDescriptor descriptor{"MotionWarpingScale", "Optional constrained scale correction."};
    return descriptor;
}
} // namespace motion

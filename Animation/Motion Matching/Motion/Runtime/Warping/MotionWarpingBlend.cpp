#include "MotionWarpingBlend.h"

namespace motion {
const ModuleDescriptor &module_motionwarpingblend() {
    static const ModuleDescriptor descriptor{"MotionWarpingBlend", "Blends warp influence smoothly."};
    return descriptor;
}
} // namespace motion

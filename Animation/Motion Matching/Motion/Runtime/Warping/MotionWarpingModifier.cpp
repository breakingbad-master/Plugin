#include "MotionWarpingModifier.h"

namespace motion {
const ModuleDescriptor &module_motionwarpingmodifier() {
    static const ModuleDescriptor descriptor{"MotionWarpingModifier", "Base interface for a warp operation."};
    return descriptor;
}
} // namespace motion

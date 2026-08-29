#include "MotionWarpingRotation.h"

namespace motion {
const ModuleDescriptor &module_motionwarpingrotation() {
    static const ModuleDescriptor descriptor{"MotionWarpingRotation", "Rotation correction."};
    return descriptor;
}
} // namespace motion

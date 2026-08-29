#include "MotionWarpingDebug.h"

namespace motion {
const ModuleDescriptor &module_motionwarpingdebug() {
    static const ModuleDescriptor descriptor{"MotionWarpingDebug", "Visualizes targets and correction."};
    return descriptor;
}
} // namespace motion

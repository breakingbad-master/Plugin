#include "MotionWarpingSystem.h"

namespace motion {
const ModuleDescriptor &module_motionwarpingsystem() {
    static const ModuleDescriptor descriptor{"MotionWarpingSystem", "Coordinates target-aware motion warping."};
    return descriptor;
}
} // namespace motion

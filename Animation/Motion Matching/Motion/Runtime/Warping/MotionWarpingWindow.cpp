#include "MotionWarpingWindow.h"

namespace motion {
const ModuleDescriptor &module_motionwarpingwindow() {
    static const ModuleDescriptor descriptor{"MotionWarpingWindow", "Defines where warping is allowed in a clip."};
    return descriptor;
}
} // namespace motion

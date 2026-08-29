#include "MotionWarpingSolver.h"

namespace motion {
const ModuleDescriptor &module_motionwarpingsolver() {
    static const ModuleDescriptor descriptor{"MotionWarpingSolver", "Solves target alignment."};
    return descriptor;
}
} // namespace motion

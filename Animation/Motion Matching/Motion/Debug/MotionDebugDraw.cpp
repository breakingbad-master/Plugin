#include "MotionDebugDraw.h"

namespace motion {
const ModuleDescriptor &module_motiondebugdraw() {
    static const ModuleDescriptor descriptor{"MotionDebugDraw", "Motion-matching-specific debug primitives."};
    return descriptor;
}
} // namespace motion

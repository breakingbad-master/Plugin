#include "WarpDebugDraw.h"

namespace motion {
const ModuleDescriptor &module_warpdebugdraw() {
    static const ModuleDescriptor descriptor{"WarpDebugDraw", "Warp target and correction visualization."};
    return descriptor;
}
} // namespace motion

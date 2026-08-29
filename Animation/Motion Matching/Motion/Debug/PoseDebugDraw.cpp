#include "PoseDebugDraw.h"

namespace motion {
const ModuleDescriptor &module_posedebugdraw() {
    static const ModuleDescriptor descriptor{"PoseDebugDraw", "Pose and bone visualization."};
    return descriptor;
}
} // namespace motion

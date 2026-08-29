#include "TrajectoryDebugDraw.h"

namespace motion {
const ModuleDescriptor &module_trajectorydebugdraw() {
    static const ModuleDescriptor descriptor{"TrajectoryDebugDraw", "Visualizes future path and sampled points."};
    return descriptor;
}
} // namespace motion

#include "TrajectoryDebugDrawSystem.h"

namespace motion {
const ModuleDescriptor &module_trajectorydebugdrawsystem() {
    static const ModuleDescriptor descriptor{"TrajectoryDebugDrawSystem", "Trajectory visualization coordinator."};
    return descriptor;
}
} // namespace motion

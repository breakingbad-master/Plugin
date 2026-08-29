#include "TrajectoryConstraint.h"

namespace motion {
const ModuleDescriptor &module_trajectoryconstraint() {
    static const ModuleDescriptor descriptor{"TrajectoryConstraint", "Applies speed, turn, slope, and gameplay constraints."};
    return descriptor;
}
} // namespace motion

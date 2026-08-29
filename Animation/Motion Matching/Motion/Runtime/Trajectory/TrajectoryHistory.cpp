#include "TrajectoryHistory.h"

namespace motion {
const ModuleDescriptor &module_trajectoryhistory() {
    static const ModuleDescriptor descriptor{"TrajectoryHistory", "Stores recent trajectory history."};
    return descriptor;
}
} // namespace motion

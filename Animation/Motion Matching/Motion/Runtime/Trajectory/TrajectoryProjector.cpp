#include "TrajectoryProjector.h"

namespace motion {
const ModuleDescriptor &module_trajectoryprojector() {
    static const ModuleDescriptor descriptor{"TrajectoryProjector", "Projects trajectory against navigation/ground constraints."};
    return descriptor;
}
} // namespace motion

#include "TrajectoryNormalizer.h"

namespace motion {
const ModuleDescriptor &module_trajectorynormalizer() {
    static const ModuleDescriptor descriptor{"TrajectoryNormalizer", "Normalizes trajectory features for matching."};
    return descriptor;
}
} // namespace motion

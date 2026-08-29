#include "TrajectorySmoother.h"

namespace motion {
const ModuleDescriptor &module_trajectorysmoother() {
    static const ModuleDescriptor descriptor{"TrajectorySmoother", "Removes noisy input and prediction changes."};
    return descriptor;
}
} // namespace motion

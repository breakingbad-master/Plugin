#include "PoseRootFeature.h"

namespace motion {
const ModuleDescriptor &module_poserootfeature() {
    static const ModuleDescriptor descriptor{"PoseRootFeature", "Root transform and velocity feature."};
    return descriptor;
}
} // namespace motion

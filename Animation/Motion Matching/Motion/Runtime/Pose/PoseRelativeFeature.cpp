#include "PoseRelativeFeature.h"

namespace motion {
const ModuleDescriptor &module_poserelativefeature() {
    static const ModuleDescriptor descriptor{"PoseRelativeFeature", "Relative transforms between important bones."};
    return descriptor;
}
} // namespace motion

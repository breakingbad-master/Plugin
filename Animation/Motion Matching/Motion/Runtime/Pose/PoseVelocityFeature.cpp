#include "PoseVelocityFeature.h"

namespace motion {
const ModuleDescriptor &module_posevelocityfeature() {
    static const ModuleDescriptor descriptor{"PoseVelocityFeature", "Bone velocity feature for motion continuity."};
    return descriptor;
}
} // namespace motion

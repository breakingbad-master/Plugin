#include "PoseAccelerationFeature.h"

namespace motion {
const ModuleDescriptor &module_poseaccelerationfeature() {
    static const ModuleDescriptor descriptor{"PoseAccelerationFeature", "Bone acceleration feature for impact and dynamic matching."};
    return descriptor;
}
} // namespace motion

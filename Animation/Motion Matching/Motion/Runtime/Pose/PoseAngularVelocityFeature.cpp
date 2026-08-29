#include "PoseAngularVelocityFeature.h"

namespace motion {
const ModuleDescriptor &module_poseangularvelocityfeature() {
    static const ModuleDescriptor descriptor{"PoseAngularVelocityFeature", "Angular velocity feature for rotations."};
    return descriptor;
}
} // namespace motion

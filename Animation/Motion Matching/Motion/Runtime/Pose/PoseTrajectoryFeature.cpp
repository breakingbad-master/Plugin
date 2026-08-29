#include "PoseTrajectoryFeature.h"

namespace motion {
const ModuleDescriptor &module_posetrajectoryfeature() {
    static const ModuleDescriptor descriptor{"PoseTrajectoryFeature", "Future trajectory feature for matching movement intent."};
    return descriptor;
}
} // namespace motion

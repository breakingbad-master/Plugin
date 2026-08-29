#include "PoseContactFeature.h"

namespace motion {
const ModuleDescriptor &module_posecontactfeature() {
    static const ModuleDescriptor descriptor{"PoseContactFeature", "Foot/hand/body contact state feature."};
    return descriptor;
}
} // namespace motion

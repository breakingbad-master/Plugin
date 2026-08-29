#include "PosePhaseFeature.h"

namespace motion {
const ModuleDescriptor &module_posephasefeature() {
    static const ModuleDescriptor descriptor{"PosePhaseFeature", "Animation phase feature for cyclic or repeated motion."};
    return descriptor;
}
} // namespace motion

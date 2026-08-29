#include "PoseFeature.h"

namespace motion {
const ModuleDescriptor &module_posefeature() {
    static const ModuleDescriptor descriptor{"PoseFeature", "Base interface for pose-derived matching features."};
    return descriptor;
}
} // namespace motion

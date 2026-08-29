#include "PoseFeatureLayout.h"

namespace motion {
const ModuleDescriptor &module_posefeaturelayout() {
    static const ModuleDescriptor descriptor{"PoseFeatureLayout", "Defines packed feature memory layout."};
    return descriptor;
}
} // namespace motion

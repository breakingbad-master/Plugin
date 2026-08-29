#include "PoseFeatureExtractor.h"

namespace motion {
const ModuleDescriptor &module_posefeatureextractor() {
    static const ModuleDescriptor descriptor{"PoseFeatureExtractor", "Extracts pose information from the active character."};
    return descriptor;
}
} // namespace motion

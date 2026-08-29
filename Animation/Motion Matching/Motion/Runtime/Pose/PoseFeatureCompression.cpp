#include "PoseFeatureCompression.h"

namespace motion {
const ModuleDescriptor &module_posefeaturecompression() {
    static const ModuleDescriptor descriptor{"PoseFeatureCompression", "Quantizes/compresses features for memory efficiency."};
    return descriptor;
}
} // namespace motion

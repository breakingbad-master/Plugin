#include "PoseHistoryFeature.h"

namespace motion {
const ModuleDescriptor &module_posehistoryfeature() {
    static const ModuleDescriptor descriptor{"PoseHistoryFeature", "Short pose-history feature for continuity."};
    return descriptor;
}
} // namespace motion

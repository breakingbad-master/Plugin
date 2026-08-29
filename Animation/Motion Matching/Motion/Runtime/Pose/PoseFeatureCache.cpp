#include "PoseFeatureCache.h"

namespace motion {
const ModuleDescriptor &module_posefeaturecache() {
    static const ModuleDescriptor descriptor{"PoseFeatureCache", "Caches extracted pose features."};
    return descriptor;
}
} // namespace motion

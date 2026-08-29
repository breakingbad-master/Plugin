#include "MMFrameCache.h"

namespace motion {
const ModuleDescriptor &module_mmframecache() {
    static const ModuleDescriptor descriptor{"MMFrameCache", "Caches reusable frame/query data to reduce repeated work."};
    return descriptor;
}
} // namespace motion

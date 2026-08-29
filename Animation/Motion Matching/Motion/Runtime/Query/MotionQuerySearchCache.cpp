#include "MotionQuerySearchCache.h"

namespace motion {
const ModuleDescriptor &module_motionquerysearchcache() {
    static const ModuleDescriptor descriptor{"MotionQuerySearchCache", "Caches repeated queries and nearby results."};
    return descriptor;
}
} // namespace motion

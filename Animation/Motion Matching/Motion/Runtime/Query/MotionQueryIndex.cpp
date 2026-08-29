#include "MotionQueryIndex.h"

namespace motion {
const ModuleDescriptor &module_motionqueryindex() {
    static const ModuleDescriptor descriptor{"MotionQueryIndex", "Index over samples for faster candidate retrieval."};
    return descriptor;
}
} // namespace motion

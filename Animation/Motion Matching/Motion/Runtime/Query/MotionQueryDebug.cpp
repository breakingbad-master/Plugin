#include "MotionQueryDebug.h"

namespace motion {
const ModuleDescriptor &module_motionquerydebug() {
    static const ModuleDescriptor descriptor{"MotionQueryDebug", "Debug visualization and statistics for query construction."};
    return descriptor;
}
} // namespace motion

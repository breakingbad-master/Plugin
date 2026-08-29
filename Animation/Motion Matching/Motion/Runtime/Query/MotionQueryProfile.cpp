#include "MotionQueryProfile.h"

namespace motion {
const ModuleDescriptor &module_motionqueryprofile() {
    static const ModuleDescriptor descriptor{"MotionQueryProfile", "Captures query timings and quality metrics."};
    return descriptor;
}
} // namespace motion

#include "MotionMatchingViewport.h"

namespace motion {
const ModuleDescriptor &module_motionmatchingviewport() {
    static const ModuleDescriptor descriptor{"MotionMatchingViewport", "Dedicated viewport for motion matching assets."};
    return descriptor;
}
} // namespace motion

#include "MotionMatchingViewportEnvironment.h"

namespace motion {
const ModuleDescriptor &module_motionmatchingviewportenvironment() {
    static const ModuleDescriptor descriptor{"MotionMatchingViewportEnvironment", "Viewport floor, lighting, and environment."};
    return descriptor;
}
} // namespace motion

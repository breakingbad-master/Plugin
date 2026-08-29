#include "MotionMatchingViewportDebug.h"

namespace motion {
const ModuleDescriptor &module_motionmatchingviewportdebug() {
    static const ModuleDescriptor descriptor{"MotionMatchingViewportDebug", "Draws trajectories, contacts, candidates, and targets."};
    return descriptor;
}
} // namespace motion

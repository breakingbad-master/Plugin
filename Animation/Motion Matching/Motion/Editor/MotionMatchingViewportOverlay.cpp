#include "MotionMatchingViewportOverlay.h"

namespace motion {
const ModuleDescriptor &module_motionmatchingviewportoverlay() {
    static const ModuleDescriptor descriptor{"MotionMatchingViewportOverlay", "Runtime/editor overlays."};
    return descriptor;
}
} // namespace motion

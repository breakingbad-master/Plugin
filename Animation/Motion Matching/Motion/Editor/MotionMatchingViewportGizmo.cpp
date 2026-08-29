#include "MotionMatchingViewportGizmo.h"

namespace motion {
const ModuleDescriptor &module_motionmatchingviewportgizmo() {
    static const ModuleDescriptor descriptor{"MotionMatchingViewportGizmo", "Transform/navigation gizmo."};
    return descriptor;
}
} // namespace motion

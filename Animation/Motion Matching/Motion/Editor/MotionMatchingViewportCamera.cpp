#include "MotionMatchingViewportCamera.h"

namespace motion {
const ModuleDescriptor &module_motionmatchingviewportcamera() {
    static const ModuleDescriptor descriptor{"MotionMatchingViewportCamera", "Viewport camera controls."};
    return descriptor;
}
} // namespace motion

#include "MotionMatchingViewportGrid.h"

namespace motion {
const ModuleDescriptor &module_motionmatchingviewportgrid() {
    static const ModuleDescriptor descriptor{"MotionMatchingViewportGrid", "3D grid and scale visualization."};
    return descriptor;
}
} // namespace motion

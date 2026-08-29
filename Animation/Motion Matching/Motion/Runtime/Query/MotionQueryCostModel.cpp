#include "MotionQueryCostModel.h"

namespace motion {
const ModuleDescriptor &module_motionquerycostmodel() {
    static const ModuleDescriptor descriptor{"MotionQueryCostModel", "Measures and limits search cost on mobile."};
    return descriptor;
}
} // namespace motion

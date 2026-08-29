#include "MotionQueryWeightProfile.h"

namespace motion {
const ModuleDescriptor &module_motionqueryweightprofile() {
    static const ModuleDescriptor descriptor{"MotionQueryWeightProfile", "Configurable weights for different feature dimensions."};
    return descriptor;
}
} // namespace motion

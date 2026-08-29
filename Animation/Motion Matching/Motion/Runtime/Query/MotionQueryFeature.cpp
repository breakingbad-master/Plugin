#include "MotionQueryFeature.h"

namespace motion {
const ModuleDescriptor &module_motionqueryfeature() {
    static const ModuleDescriptor descriptor{"MotionQueryFeature", "Base feature interface for searchable motion information."};
    return descriptor;
}
} // namespace motion

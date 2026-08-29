#include "MotionQueryContext.h"

namespace motion {
const ModuleDescriptor &module_motionquerycontext() {
    static const ModuleDescriptor descriptor{"MotionQueryContext", "Context passed into query generation and feature extraction."};
    return descriptor;
}
} // namespace motion

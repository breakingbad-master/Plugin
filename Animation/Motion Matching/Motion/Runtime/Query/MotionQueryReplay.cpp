#include "MotionQueryReplay.h"

namespace motion {
const ModuleDescriptor &module_motionqueryreplay() {
    static const ModuleDescriptor descriptor{"MotionQueryReplay", "Records queries/results for regression testing."};
    return descriptor;
}
} // namespace motion

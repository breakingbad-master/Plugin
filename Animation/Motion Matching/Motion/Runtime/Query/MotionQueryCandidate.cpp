#include "MotionQueryCandidate.h"

namespace motion {
const ModuleDescriptor &module_motionquerycandidate() {
    static const ModuleDescriptor descriptor{"MotionQueryCandidate", "Represents one searchable animation sample candidate."};
    return descriptor;
}
} // namespace motion

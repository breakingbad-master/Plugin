#include "MotionQueryCandidateFilter.h"

namespace motion {
const ModuleDescriptor &module_motionquerycandidatefilter() {
    static const ModuleDescriptor descriptor{"MotionQueryCandidateFilter", "Rejects invalid, incompatible, or gameplay-blocked candidates."};
    return descriptor;
}
} // namespace motion

#include "PosePhaseScorer.h"

namespace motion {
const ModuleDescriptor &module_posephasescorer() {
    static const ModuleDescriptor descriptor{"PosePhaseScorer", "Scores cyclic phase continuity."};
    return descriptor;
}
} // namespace motion

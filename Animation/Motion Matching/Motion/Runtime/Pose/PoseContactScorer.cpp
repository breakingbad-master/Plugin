#include "PoseContactScorer.h"

namespace motion {
const ModuleDescriptor &module_posecontactscorer() {
    static const ModuleDescriptor descriptor{"PoseContactScorer", "Scores contact consistency."};
    return descriptor;
}
} // namespace motion

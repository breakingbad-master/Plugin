#include "PoseDistanceWeights.h"

namespace motion {
const ModuleDescriptor &module_posedistanceweights() {
    static const ModuleDescriptor descriptor{"PoseDistanceWeights", "Per-feature and per-bone scoring weights."};
    return descriptor;
}
} // namespace motion

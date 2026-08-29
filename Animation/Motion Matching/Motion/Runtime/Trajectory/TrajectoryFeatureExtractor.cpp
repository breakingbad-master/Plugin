#include "TrajectoryFeatureExtractor.h"

namespace motion {
const ModuleDescriptor &module_trajectoryfeatureextractor() {
    static const ModuleDescriptor descriptor{"TrajectoryFeatureExtractor", "Creates searchable trajectory features."};
    return descriptor;
}
} // namespace motion

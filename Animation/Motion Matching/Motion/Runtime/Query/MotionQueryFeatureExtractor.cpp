#include "MotionQueryFeatureExtractor.h"

namespace motion {
const ModuleDescriptor &module_motionqueryfeatureextractor() {
    static const ModuleDescriptor descriptor{"MotionQueryFeatureExtractor", "Extracts searchable features from current state and target intent."};
    return descriptor;
}
} // namespace motion

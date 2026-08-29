#include "MotionQueryFeatureVector.h"

namespace motion {
const ModuleDescriptor &module_motionqueryfeaturevector() {
    static const ModuleDescriptor descriptor{"MotionQueryFeatureVector", "Packed numeric feature vector for fast comparisons."};
    return descriptor;
}
} // namespace motion

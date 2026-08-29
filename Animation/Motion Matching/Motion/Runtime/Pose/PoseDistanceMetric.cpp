#include "PoseDistanceMetric.h"

namespace motion {
const ModuleDescriptor &module_posedistancemetric() {
    static const ModuleDescriptor descriptor{"PoseDistanceMetric", "Distance calculation between query and candidate features."};
    return descriptor;
}
} // namespace motion

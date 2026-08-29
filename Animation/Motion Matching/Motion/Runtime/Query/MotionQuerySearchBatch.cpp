#include "MotionQuerySearchBatch.h"

namespace motion {
const ModuleDescriptor &module_motionquerysearchbatch() {
    static const ModuleDescriptor descriptor{"MotionQuerySearchBatch", "Batched search for multiple agents."};
    return descriptor;
}
} // namespace motion

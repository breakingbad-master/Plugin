#include "MotionQuerySearch.h"

namespace motion {
const ModuleDescriptor &module_motionquerysearch() {
    static const ModuleDescriptor descriptor{"MotionQuerySearch", "Executes candidate retrieval and ranking."};
    return descriptor;
}
} // namespace motion

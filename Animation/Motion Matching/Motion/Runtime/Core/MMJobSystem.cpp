#include "MMJobSystem.h"

namespace motion {
const ModuleDescriptor &module_mmjobsystem() {
    static const ModuleDescriptor descriptor{"MMJobSystem", "Small jobs for feature extraction, candidate scoring, and database queries."};
    return descriptor;
}
} // namespace motion

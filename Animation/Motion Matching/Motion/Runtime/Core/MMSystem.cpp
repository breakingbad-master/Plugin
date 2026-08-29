#include "MMSystem.h"

namespace motion {
const ModuleDescriptor &module_mmsystem() {
    static const ModuleDescriptor descriptor{"MMSystem", "Main runtime coordinator for motion-matching evaluation, lifecycle, and integration."};
    return descriptor;
}
} // namespace motion

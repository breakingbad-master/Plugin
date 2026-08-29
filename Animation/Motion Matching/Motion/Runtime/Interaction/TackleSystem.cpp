#include "TackleSystem.h"

namespace motion {
const ModuleDescriptor &module_tacklesystem() {
    static const ModuleDescriptor descriptor{"TackleSystem", "General tackle interaction."};
    return descriptor;
}
} // namespace motion

#include "IdleSystem.h"

namespace motion {
const ModuleDescriptor &module_idlesystem() {
    static const ModuleDescriptor descriptor{"IdleSystem", "General idle selection supporting many idle variants."};
    return descriptor;
}
} // namespace motion

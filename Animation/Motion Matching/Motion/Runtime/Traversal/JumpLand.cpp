#include "JumpLand.h"

namespace motion {
const ModuleDescriptor &module_jumpland() {
    static const ModuleDescriptor descriptor{"JumpLand", "Landing phase handling."};
    return descriptor;
}
} // namespace motion

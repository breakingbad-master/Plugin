#include "ActionCooldown.h"

namespace motion {
const ModuleDescriptor &module_actioncooldown() {
    static const ModuleDescriptor descriptor{"ActionCooldown", "Controls repeated actions."};
    return descriptor;
}
} // namespace motion

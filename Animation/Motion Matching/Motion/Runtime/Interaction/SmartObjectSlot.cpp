#include "SmartObjectSlot.h"

namespace motion {
const ModuleDescriptor &module_smartobjectslot() {
    static const ModuleDescriptor descriptor{"SmartObjectSlot", "Interaction slot and transform."};
    return descriptor;
}
} // namespace motion

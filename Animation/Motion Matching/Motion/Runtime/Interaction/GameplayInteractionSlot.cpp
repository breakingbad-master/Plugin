#include "GameplayInteractionSlot.h"

namespace motion {
const ModuleDescriptor &module_gameplayinteractionslot() {
    static const ModuleDescriptor descriptor{"GameplayInteractionSlot", "Defines an interaction position/orientation."};
    return descriptor;
}
} // namespace motion

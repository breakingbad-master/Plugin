#include "GameplayInteractionTarget.h"

namespace motion {
const ModuleDescriptor &module_gameplayinteractiontarget() {
    static const ModuleDescriptor descriptor{"GameplayInteractionTarget", "Represents a target actor/object."};
    return descriptor;
}
} // namespace motion

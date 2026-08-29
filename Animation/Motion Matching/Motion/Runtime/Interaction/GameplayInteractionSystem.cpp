#include "GameplayInteractionSystem.h"

namespace motion {
const ModuleDescriptor &module_gameplayinteractionsystem() {
    static const ModuleDescriptor descriptor{"GameplayInteractionSystem", "General interaction framework for characters, props, and gameplay actions."};
    return descriptor;
}
} // namespace motion

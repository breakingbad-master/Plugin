#include "GameplayInteractionContext.h"

namespace motion {
const ModuleDescriptor &module_gameplayinteractioncontext() {
    static const ModuleDescriptor descriptor{"GameplayInteractionContext", "Runtime context for interaction selection."};
    return descriptor;
}
} // namespace motion

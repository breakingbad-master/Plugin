#include "GameplayInteractionResolver.h"

namespace motion {
const ModuleDescriptor &module_gameplayinteractionresolver() {
    static const ModuleDescriptor descriptor{"GameplayInteractionResolver", "Resolves the best compatible interaction."};
    return descriptor;
}
} // namespace motion

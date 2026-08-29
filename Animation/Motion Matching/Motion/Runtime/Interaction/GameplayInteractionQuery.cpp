#include "GameplayInteractionQuery.h"

namespace motion {
const ModuleDescriptor &module_gameplayinteractionquery() {
    static const ModuleDescriptor descriptor{"GameplayInteractionQuery", "Finds compatible interaction opportunities."};
    return descriptor;
}
} // namespace motion

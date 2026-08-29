#include "GameplayInteractionAlignment.h"

namespace motion {
const ModuleDescriptor &module_gameplayinteractionalignment() {
    static const ModuleDescriptor descriptor{"GameplayInteractionAlignment", "Aligns participants before animation."};
    return descriptor;
}
} // namespace motion

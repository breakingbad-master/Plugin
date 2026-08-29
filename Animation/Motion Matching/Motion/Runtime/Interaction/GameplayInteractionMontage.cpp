#include "GameplayInteractionMontage.h"

namespace motion {
const ModuleDescriptor &module_gameplayinteractionmontage() {
    static const ModuleDescriptor descriptor{"GameplayInteractionMontage", "Coordinates multi-stage interaction animation."};
    return descriptor;
}
} // namespace motion

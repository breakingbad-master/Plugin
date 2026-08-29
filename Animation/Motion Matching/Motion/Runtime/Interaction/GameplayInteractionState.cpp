#include "GameplayInteractionState.h"

namespace motion {
const ModuleDescriptor &module_gameplayinteractionstate() {
    static const ModuleDescriptor descriptor{"GameplayInteractionState", "Tracks interaction lifecycle."};
    return descriptor;
}
} // namespace motion

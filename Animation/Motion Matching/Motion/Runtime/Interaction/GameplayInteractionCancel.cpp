#include "GameplayInteractionCancel.h"

namespace motion {
const ModuleDescriptor &module_gameplayinteractioncancel() {
    static const ModuleDescriptor descriptor{"GameplayInteractionCancel", "Safe interruption and recovery."};
    return descriptor;
}
} // namespace motion

#include "GameplayInteractionReservation.h"

namespace motion {
const ModuleDescriptor &module_gameplayinteractionreservation() {
    static const ModuleDescriptor descriptor{"GameplayInteractionReservation", "Prevents two agents claiming one interaction."};
    return descriptor;
}
} // namespace motion

#include "LocomotionTransition.h"

namespace motion {
const ModuleDescriptor &module_locomotiontransition() {
    static const ModuleDescriptor descriptor{"LocomotionTransition", "Transition rules between movement states."};
    return descriptor;
}
} // namespace motion

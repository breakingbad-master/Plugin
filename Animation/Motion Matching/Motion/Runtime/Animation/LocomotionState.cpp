#include "LocomotionState.h"

namespace motion {
const ModuleDescriptor &module_locomotionstate() {
    static const ModuleDescriptor descriptor{"LocomotionState", "Runtime locomotion state representation."};
    return descriptor;
}
} // namespace motion

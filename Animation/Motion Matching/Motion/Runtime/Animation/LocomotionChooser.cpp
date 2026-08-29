#include "LocomotionChooser.h"

namespace motion {
const ModuleDescriptor &module_locomotionchooser() {
    static const ModuleDescriptor descriptor{"LocomotionChooser", "Chooses suitable locomotion variants."};
    return descriptor;
}
} // namespace motion

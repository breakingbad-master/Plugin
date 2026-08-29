#include "LocomotionLibrary.h"

namespace motion {
const ModuleDescriptor &module_locomotionlibrary() {
    static const ModuleDescriptor descriptor{"LocomotionLibrary", "Locomotion-specific library built on the general animation system."};
    return descriptor;
}
} // namespace motion

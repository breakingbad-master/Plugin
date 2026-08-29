#include "TakedownAnimationResolver.h"

namespace motion {
const ModuleDescriptor &module_takedownanimationresolver() {
    static const ModuleDescriptor descriptor{"TakedownAnimationResolver", "Selects takedown variants."};
    return descriptor;
}
} // namespace motion

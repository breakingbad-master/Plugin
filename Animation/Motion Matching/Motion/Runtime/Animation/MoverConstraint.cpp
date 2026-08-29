#include "MoverConstraint.h"

namespace motion {
const ModuleDescriptor &module_moverconstraint() {
    static const ModuleDescriptor descriptor{"MoverConstraint", "Applies movement limits and gameplay constraints."};
    return descriptor;
}
} // namespace motion

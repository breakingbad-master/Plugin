#include "ActionVariantResolver.h"

namespace motion {
const ModuleDescriptor &module_actionvariantresolver() {
    static const ModuleDescriptor descriptor{"ActionVariantResolver", "Selects variants for generic actions."};
    return descriptor;
}
} // namespace motion

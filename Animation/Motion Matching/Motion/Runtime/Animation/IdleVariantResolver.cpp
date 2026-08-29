#include "IdleVariantResolver.h"

namespace motion {
const ModuleDescriptor &module_idlevariantresolver() {
    static const ModuleDescriptor descriptor{"IdleVariantResolver", "Chooses idle based on context/history."};
    return descriptor;
}
} // namespace motion

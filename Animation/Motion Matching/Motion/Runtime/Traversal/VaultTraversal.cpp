#include "VaultTraversal.h"

namespace motion {
const ModuleDescriptor &module_vaulttraversal() {
    static const ModuleDescriptor descriptor{"VaultTraversal", "Vault action logic."};
    return descriptor;
}
} // namespace motion

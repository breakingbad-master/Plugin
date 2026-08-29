#include "RagdollRecovery.h"

namespace motion {
const ModuleDescriptor &module_ragdollrecovery() {
    static const ModuleDescriptor descriptor{"RagdollRecovery", "Returns from ragdoll to valid animation."};
    return descriptor;
}
} // namespace motion

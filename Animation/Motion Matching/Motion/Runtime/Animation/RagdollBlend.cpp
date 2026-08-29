#include "RagdollBlend.h"

namespace motion {
const ModuleDescriptor &module_ragdollblend() {
    static const ModuleDescriptor descriptor{"RagdollBlend", "Blends ragdoll back into animation."};
    return descriptor;
}
} // namespace motion

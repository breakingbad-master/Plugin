#include "RagdollSystem.h"

namespace motion {
const ModuleDescriptor &module_ragdollsystem() {
    static const ModuleDescriptor descriptor{"RagdollSystem", "Runtime ragdoll activation and recovery."};
    return descriptor;
}
} // namespace motion

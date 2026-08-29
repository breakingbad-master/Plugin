#include "RagdollPoseMatcher.h"

namespace motion {
const ModuleDescriptor &module_ragdollposematcher() {
    static const ModuleDescriptor descriptor{"RagdollPoseMatcher", "Finds a suitable recovery pose."};
    return descriptor;
}
} // namespace motion

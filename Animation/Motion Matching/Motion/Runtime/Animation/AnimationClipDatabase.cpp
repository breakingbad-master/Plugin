#include "AnimationClipDatabase.h"

namespace motion {
const ModuleDescriptor &module_animationclipdatabase() {
    static const ModuleDescriptor descriptor{"AnimationClipDatabase", "Metadata and lookup for animation clips."};
    return descriptor;
}
} // namespace motion

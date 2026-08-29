#include "AnimationLibrary.h"

namespace motion {
const ModuleDescriptor &module_animationlibrary() {
    static const ModuleDescriptor descriptor{"AnimationLibrary", "Runtime registry for all animation assets and clips."};
    return descriptor;
}
} // namespace motion

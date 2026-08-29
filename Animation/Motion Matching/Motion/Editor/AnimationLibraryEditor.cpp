#include "AnimationLibraryEditor.h"

namespace motion {
const ModuleDescriptor &module_animationlibraryeditor() {
    static const ModuleDescriptor descriptor{"AnimationLibraryEditor", "Animation library browser."};
    return descriptor;
}
} // namespace motion

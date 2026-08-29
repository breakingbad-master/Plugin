#include "AnimationLibraryStreaming.h"

namespace motion {
const ModuleDescriptor &module_animationlibrarystreaming() {
    static const ModuleDescriptor descriptor{"AnimationLibraryStreaming", "Streams animation data on demand."};
    return descriptor;
}
} // namespace motion

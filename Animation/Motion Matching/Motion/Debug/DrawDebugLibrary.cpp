#include "DrawDebugLibrary.h"

namespace motion {
const ModuleDescriptor &module_drawdebuglibrary() {
    static const ModuleDescriptor descriptor{"DrawDebugLibrary", "Shared debug drawing API for lines, spheres, capsules, arrows, and text."};
    return descriptor;
}
} // namespace motion

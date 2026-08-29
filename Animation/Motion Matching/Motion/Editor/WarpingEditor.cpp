#include "WarpingEditor.h"

namespace motion {
const ModuleDescriptor &module_warpingeditor() {
    static const ModuleDescriptor descriptor{"WarpingEditor", "Warping windows and modifier editor."};
    return descriptor;
}
} // namespace motion

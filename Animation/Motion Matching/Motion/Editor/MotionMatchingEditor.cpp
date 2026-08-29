#include "MotionMatchingEditor.h"

namespace motion {
const ModuleDescriptor &module_motionmatchingeditor() {
    static const ModuleDescriptor descriptor{"MotionMatchingEditor", "Editor module for authoring and inspecting motion matching."};
    return descriptor;
}
} // namespace motion

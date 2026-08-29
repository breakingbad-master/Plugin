#include "MotionMatchingEditorToolbar.h"

namespace motion {
const ModuleDescriptor &module_motionmatchingeditortoolbar() {
    static const ModuleDescriptor descriptor{"MotionMatchingEditorToolbar", "Editor controls and quality/debug controls."};
    return descriptor;
}
} // namespace motion

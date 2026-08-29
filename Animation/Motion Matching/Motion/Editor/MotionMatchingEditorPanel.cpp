#include "MotionMatchingEditorPanel.h"

namespace motion {
const ModuleDescriptor &module_motionmatchingeditorpanel() {
    static const ModuleDescriptor descriptor{"MotionMatchingEditorPanel", "Main editor panel."};
    return descriptor;
}
} // namespace motion

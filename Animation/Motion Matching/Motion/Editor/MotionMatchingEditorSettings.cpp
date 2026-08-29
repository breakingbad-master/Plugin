#include "MotionMatchingEditorSettings.h"

namespace motion {
const ModuleDescriptor &module_motionmatchingeditorsettings() {
    static const ModuleDescriptor descriptor{"MotionMatchingEditorSettings", "Persistent editor settings."};
    return descriptor;
}
} // namespace motion

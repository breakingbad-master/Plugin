#include "MotionQueryEditor.h"

namespace motion {
const ModuleDescriptor &module_motionqueryeditor() {
    static const ModuleDescriptor descriptor{"MotionQueryEditor", "Authoring UI for motion queries."};
    return descriptor;
}
} // namespace motion

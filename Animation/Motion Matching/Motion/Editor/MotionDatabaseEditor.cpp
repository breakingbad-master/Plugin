#include "MotionDatabaseEditor.h"

namespace motion {
const ModuleDescriptor &module_motiondatabaseeditor() {
    static const ModuleDescriptor descriptor{"MotionDatabaseEditor", "Database inspection and rebuild UI."};
    return descriptor;
}
} // namespace motion

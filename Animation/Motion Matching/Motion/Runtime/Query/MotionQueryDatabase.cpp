#include "MotionQueryDatabase.h"

namespace motion {
const ModuleDescriptor &module_motionquerydatabase() {
    static const ModuleDescriptor descriptor{"MotionQueryDatabase", "Runtime searchable collection of motion samples."};
    return descriptor;
}
} // namespace motion

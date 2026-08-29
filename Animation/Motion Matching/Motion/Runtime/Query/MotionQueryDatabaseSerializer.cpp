#include "MotionQueryDatabaseSerializer.h"

namespace motion {
const ModuleDescriptor &module_motionquerydatabaseserializer() {
    static const ModuleDescriptor descriptor{"MotionQueryDatabaseSerializer", "Loads/saves database data efficiently."};
    return descriptor;
}
} // namespace motion

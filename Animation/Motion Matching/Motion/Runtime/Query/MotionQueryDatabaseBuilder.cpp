#include "MotionQueryDatabaseBuilder.h"

namespace motion {
const ModuleDescriptor &module_motionquerydatabasebuilder() {
    static const ModuleDescriptor descriptor{"MotionQueryDatabaseBuilder", "Builds databases from animation clips and sampled poses."};
    return descriptor;
}
} // namespace motion

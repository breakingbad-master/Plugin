#include "MotionQueryBuilder.h"

namespace motion {
const ModuleDescriptor &module_motionquerybuilder() {
    static const ModuleDescriptor descriptor{"MotionQueryBuilder", "Builds queries from gameplay state, pose, trajectory, contacts, and tags."};
    return descriptor;
}
} // namespace motion

#include "MMUpdateScheduler.h"

namespace motion {
const ModuleDescriptor &module_mmupdatescheduler() {
    static const ModuleDescriptor descriptor{"MMUpdateScheduler", "Schedules animation evaluation at configurable frequencies for mobile performance."};
    return descriptor;
}
} // namespace motion

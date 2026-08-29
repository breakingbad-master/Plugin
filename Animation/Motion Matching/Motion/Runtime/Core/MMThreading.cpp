#include "MMThreading.h"

namespace motion {
const ModuleDescriptor &module_mmthreading() {
    static const ModuleDescriptor descriptor{"MMThreading", "Threading policy and worker orchestration for background query/search work."};
    return descriptor;
}
} // namespace motion

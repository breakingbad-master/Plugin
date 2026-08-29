#include "TrajectorySampler.h"

namespace motion {
const ModuleDescriptor &module_trajectorysampler() {
    static const ModuleDescriptor descriptor{"TrajectorySampler", "Samples future positions, rotations, and velocities."};
    return descriptor;
}
} // namespace motion

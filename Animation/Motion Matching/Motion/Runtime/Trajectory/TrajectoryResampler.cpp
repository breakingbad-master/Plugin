#include "TrajectoryResampler.h"

namespace motion {
const ModuleDescriptor &module_trajectoryresampler() {
    static const ModuleDescriptor descriptor{"TrajectoryResampler", "Resamples trajectory at fixed time intervals."};
    return descriptor;
}
} // namespace motion

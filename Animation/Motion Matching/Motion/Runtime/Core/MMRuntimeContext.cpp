#include "MMRuntimeContext.h"

#include <algorithm>
#include <cmath>

namespace motion {

bool MMRuntimeContext::valid() const {
    return std::isfinite(delta_seconds) && delta_seconds >= 0.0f && budget.max_candidates > 0 &&
           budget.max_results > 0 && std::isfinite(root_position.x) && std::isfinite(root_position.y) &&
           std::isfinite(root_position.z) && std::isfinite(root_velocity.x) && std::isfinite(root_velocity.y) &&
           std::isfinite(root_velocity.z);
}

void MMRuntimeContext::advance(float delta) {
    delta_seconds = std::max(0.0f, delta);
    ++frame;
}

const ModuleDescriptor &module_mmruntimecontext() {
    static const ModuleDescriptor descriptor{
        "MMRuntimeContext", "Validated per-frame agent state with budgets, root motion, and monotonic frame tokens."};
    return descriptor;
}

} // namespace motion

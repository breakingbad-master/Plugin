#include "PoseContinuityScorer.h"

#include <algorithm>
#include <cmath>
#include <limits>

namespace motion {

float PoseContinuityScorer::score(const std::vector<float> &previous,
                                  const std::vector<float> &next, float weight) {
    if (!std::isfinite(weight)) return std::numeric_limits<float>::infinity();
    const float safe_weight = std::max(0.0f, weight);
    const std::size_t dimensions = std::max(previous.size(), next.size());
    float total = 0.0f;
    for (std::size_t i = 0; i < dimensions; ++i) {
        const float a = i < previous.size() ? previous[i] : 0.0f;
        const float b = i < next.size() ? next[i] : 0.0f;
        if (!std::isfinite(a) || !std::isfinite(b)) return std::numeric_limits<float>::infinity();
        total += std::fabs(a - b) * safe_weight;
    }
    return total;
}

const ModuleDescriptor &module_posecontinuityscorer() {
    static const ModuleDescriptor descriptor{
        "PoseContinuityScorer", "Dimension-safe weighted transition continuity penalty."};
    return descriptor;
}

} // namespace motion

#include "MotionQueryProfile.h"

#include <algorithm>
#include <cmath>

namespace motion {

void MotionQueryProfiler::reset() { stats_ = {}; }

void MotionQueryProfiler::record_search(float elapsed_ms, const SearchResult &result, bool cache_hit) {
    const float safe_elapsed = std::isfinite(elapsed_ms) ? std::max(0.0f, elapsed_ms) : 0.0f;
    ++stats_.searches;
    if (cache_hit) ++stats_.cache_hits;
    stats_.candidates_evaluated += result.evaluated;
    stats_.candidates_filtered += result.filtered;
    stats_.total_search_ms += safe_elapsed;
    stats_.worst_search_ms = std::max(stats_.worst_search_ms, safe_elapsed);
    stats_.average_search_ms = stats_.total_search_ms / static_cast<float>(stats_.searches);
}

MotionQueryProfileSnapshot MotionQueryProfiler::snapshot() const { return stats_; }

float MotionQueryProfiler::cache_hit_ratio() const {
    return stats_.searches == 0 ? 0.0f
        : static_cast<float>(stats_.cache_hits) / static_cast<float>(stats_.searches);
}

const ModuleDescriptor &module_motionqueryprofile() {
    static const ModuleDescriptor descriptor{
        "MotionQueryProfile", "Query timing, candidate quality, and cache-hit metrics for runtime budgets."};
    return descriptor;
}

} // namespace motion

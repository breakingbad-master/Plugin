#include "../Runtime/Query/MotionQueryProfile.h"

#include <cmath>
#include <iostream>
#include <limits>

using namespace motion;

int main() {
    MotionQueryProfiler profiler;
    SearchResult result;
    result.evaluated = 4;
    result.filtered = 1;
    profiler.record_search(2.0f, result, false);
    profiler.record_search(std::numeric_limits<float>::quiet_NaN(), result, true);
    const auto snapshot = profiler.snapshot();
    if (snapshot.searches != 2 || snapshot.cache_hits != 1 || snapshot.candidates_evaluated != 8 ||
        snapshot.candidates_filtered != 2 || std::fabs(snapshot.total_search_ms - 2.0f) > 0.0001f ||
        std::fabs(snapshot.average_search_ms - 1.0f) > 0.0001f ||
        std::fabs(snapshot.worst_search_ms - 2.0f) > 0.0001f ||
        std::fabs(profiler.cache_hit_ratio() - 0.5f) > 0.0001f) return 1;
    profiler.reset();
    if (profiler.snapshot().searches != 0 || profiler.cache_hit_ratio() != 0.0f) return 1;
    std::cout << "MotionQueryProfileTests passed\n";
    return 0;
}

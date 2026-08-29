#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <cstddef>

namespace motion {

struct MotionQueryProfileSnapshot {
    std::size_t searches = 0;
    std::size_t cache_hits = 0;
    std::size_t candidates_evaluated = 0;
    std::size_t candidates_filtered = 0;
    float total_search_ms = 0.0f;
    float worst_search_ms = 0.0f;
    float average_search_ms = 0.0f;
};

class MotionQueryProfiler {
public:
    void reset();
    void record_search(float elapsed_ms, const SearchResult &result, bool cache_hit = false);
    MotionQueryProfileSnapshot snapshot() const;
    float cache_hit_ratio() const;

private:
    MotionQueryProfileSnapshot stats_;
};

const ModuleDescriptor &module_motionqueryprofile();

} // namespace motion

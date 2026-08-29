#include "motion_matching_c_api.h"

#include "../../Animation/Motion Matching/Motion/Runtime/Core/MMCore.h"
#include "../../Animation/Motion Matching/Motion/Runtime/Query/MotionQueryDatabase.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <new>

struct MMRuntimeHandle {
    motion::MotionQueryDatabase database;
    motion::MotionMatcher matcher;
};

namespace {

bool finite(float value) { return std::isfinite(value); }

motion::MotionCandidate convert_candidate(const MMRuntimeCandidateInput &input) {
    motion::MotionCandidate candidate;
    candidate.clip_id = input.clip_id ? input.clip_id : "";
    candidate.frame = input.frame;
    candidate.max_obstacle_height = finite(input.max_obstacle_height)
        ? input.max_obstacle_height : std::numeric_limits<float>::infinity();
    candidate.min_clearance = finite(input.min_clearance) ? std::max(0.0f, input.min_clearance) : 0.0f;
    candidate.min_speed = finite(input.min_speed) ? std::max(0.0f, input.min_speed) : 0.0f;
    candidate.max_speed = finite(input.max_speed) && input.max_speed >= 0.0f
        ? input.max_speed : std::numeric_limits<float>::infinity();
    candidate.fallback = input.fallback != 0;
    if (input.features && input.feature_count) {
        candidate.features.assign(input.features, input.features + input.feature_count);
    }
    if (input.tags) {
        for (size_t i = 0; i < input.tag_count; ++i) {
            if (input.tags[i]) candidate.tags.emplace_back(input.tags[i]);
        }
    }
    return candidate;
}

motion::MotionQuery convert_query(const MMRuntimeQueryInput &input) {
    motion::MotionQuery query;
    query.frame = input.frame;
    if (input.features && input.feature_count) query.features.assign(input.features, input.features + input.feature_count);
    query.environment.valid = input.environment_valid != 0;
    query.environment.blocked = input.environment_blocked != 0;
    query.environment.obstacle_distance = finite(input.obstacle_distance) ? input.obstacle_distance : 0.0f;
    query.environment.obstacle_height = finite(input.obstacle_height) ? input.obstacle_height : 0.0f;
    query.environment.clearance = finite(input.clearance) ? input.clearance : 0.0f;
    query.environment.ground_height = finite(input.ground_height) ? input.ground_height : 0.0f;
    return query;
}

} // namespace

extern "C" MMRuntimeHandle *mm_runtime_create(void) {
    return new (std::nothrow) MMRuntimeHandle();
}

extern "C" void mm_runtime_destroy(MMRuntimeHandle *handle) { delete handle; }

extern "C" void mm_runtime_clear(MMRuntimeHandle *handle) {
    if (handle) handle->database.clear();
}

extern "C" int mm_runtime_add_candidate(MMRuntimeHandle *handle, const MMRuntimeCandidateInput *input) {
    if (!handle || !input) return 0;
    handle->database.add(convert_candidate(*input));
    return 1;
}

extern "C" int mm_runtime_search(const MMRuntimeHandle *handle, const MMRuntimeQueryInput *input,
                                  size_t max_candidates, size_t max_results, MMRuntimeSearchOutput *output) {
    if (!handle || !input || !output) return 0;
    motion::SearchBudget budget;
    budget.max_candidates = max_candidates;
    budget.max_results = max_results;
    const motion::MotionQuery query = convert_query(*input);
    const motion::SearchResult result = handle->matcher.search(query, handle->database, budget, nullptr);
    output->selected_index = result.selected.candidate
        ? static_cast<size_t>(result.selected.candidate - handle->database.samples().data()) : SIZE_MAX;
    output->selected_score = result.selected.total;
    output->evaluated = result.evaluated;
    output->filtered = result.filtered;
    output->used_fallback = result.used_fallback ? 1 : 0;
    return 1;
}

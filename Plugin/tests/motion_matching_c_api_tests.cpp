#include "../src/motion_matching_c_api.h"

#include <cmath>
#include <iostream>

int main() {
    MMRuntimeHandle *runtime = mm_runtime_create();
    if (!runtime) return 1;
    const float candidate_features[] = {0.0f, 1.0f};
    const char *tags[] = {"locomotion"};
    MMRuntimeCandidateInput candidate{};
    candidate.clip_id = "walk";
    candidate.frame = 12;
    candidate.features = candidate_features;
    candidate.feature_count = 2;
    candidate.tags = tags;
    candidate.tag_count = 1;
    candidate.max_obstacle_height = 100.0f;
    candidate.max_speed = 10.0f;
    if (!mm_runtime_add_candidate(runtime, &candidate)) {
        mm_runtime_destroy(runtime);
        return 1;
    }
    const float query_features[] = {0.0f, 1.0f};
    MMRuntimeQueryInput query{};
    query.features = query_features;
    query.feature_count = 2;
    MMRuntimeSearchOutput output{};
    if (!mm_runtime_search(runtime, &query, 16, 1, &output) || output.selected_index != 0 ||
        !std::isfinite(output.selected_score) || output.evaluated != 1) {
        mm_runtime_destroy(runtime);
        return 1;
    }
    mm_runtime_clear(runtime);
    mm_runtime_destroy(runtime);
    std::cout << "MotionRuntimeCapiTests passed\n";
    return 0;
}

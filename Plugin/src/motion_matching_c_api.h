#pragma once

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MMRuntimeHandle MMRuntimeHandle;
typedef struct MMRuntimeCandidateInput {
    const char *clip_id;
    size_t frame;
    const float *features;
    size_t feature_count;
    const char *const *tags;
    size_t tag_count;
    float max_obstacle_height;
    float min_clearance;
    float min_speed;
    float max_speed;
    int fallback;
} MMRuntimeCandidateInput;

typedef struct MMRuntimeQueryInput {
    const float *features;
    size_t feature_count;
    unsigned long long frame;
    int environment_valid;
    int environment_blocked;
    float obstacle_distance;
    float obstacle_height;
    float clearance;
    float ground_height;
} MMRuntimeQueryInput;

typedef struct MMRuntimeSearchOutput {
    size_t selected_index;
    float selected_score;
    size_t evaluated;
    size_t filtered;
    int used_fallback;
} MMRuntimeSearchOutput;

MMRuntimeHandle *mm_runtime_create(void);
void mm_runtime_destroy(MMRuntimeHandle *handle);
void mm_runtime_clear(MMRuntimeHandle *handle);
int mm_runtime_add_candidate(MMRuntimeHandle *handle, const MMRuntimeCandidateInput *input);
int mm_runtime_search(const MMRuntimeHandle *handle, const MMRuntimeQueryInput *input,
                      size_t max_candidates, size_t max_results, MMRuntimeSearchOutput *output);

#ifdef __cplusplus
}
#endif

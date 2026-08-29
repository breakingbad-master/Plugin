#pragma once

#include <cstddef>

namespace motion {

struct MobileQualityTier {
    std::size_t max_agents = 16;
    std::size_t max_candidates = 128;
    std::size_t max_pose_samples = 32;
    std::size_t max_query_jobs_per_frame = 4;
    std::size_t memory_budget_kb = 4096;
    float update_hz = 30.0f;
    std::size_t debug_frames_per_second = 0;
};

class MMMobileBudget {
public:
    static MobileQualityTier low();
    static MobileQualityTier medium();
    static MobileQualityTier high();
    static MobileQualityTier clamp_for_android(MobileQualityTier tier);
};

} // namespace motion

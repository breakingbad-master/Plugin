#include "MMMobileBudget.h"

#include <algorithm>

namespace motion {

MobileQualityTier MMMobileBudget::low() { return {8, 48, 16, 1, 2048, 15.0f, 0}; }
MobileQualityTier MMMobileBudget::medium() { return {16, 128, 32, 4, 4096, 30.0f, 0}; }
MobileQualityTier MMMobileBudget::high() { return {32, 256, 64, 8, 8192, 45.0f, 2}; }

MobileQualityTier MMMobileBudget::clamp_for_android(MobileQualityTier tier) {
    tier.max_agents = std::clamp<std::size_t>(tier.max_agents, 1, 32);
    tier.max_candidates = std::clamp<std::size_t>(tier.max_candidates, 8, 256);
    tier.max_pose_samples = std::clamp<std::size_t>(tier.max_pose_samples, 4, 64);
    tier.max_query_jobs_per_frame = std::clamp<std::size_t>(tier.max_query_jobs_per_frame, 1, 8);
    tier.memory_budget_kb = std::clamp<std::size_t>(tier.memory_budget_kb, 512, 8192);
    tier.update_hz = std::clamp(tier.update_hz, 10.0f, 60.0f);
    tier.debug_frames_per_second = std::min<std::size_t>(tier.debug_frames_per_second, 5);
    return tier;
}

} // namespace motion

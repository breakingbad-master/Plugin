#include "MotionQueryDatabaseBuilder.h"

#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_set>

namespace motion {

MotionQueryDatabaseBuildStats MotionQueryDatabaseBuilder::build(const std::vector<MotionCandidate> &candidates,
                                                                MotionQueryDatabase &database) const {
    MotionQueryDatabaseBuildStats stats;
    stats.input_count = candidates.size();
    database.clear();
    std::size_t dimensions = 0;
    for (const auto &candidate : candidates) dimensions = std::max(dimensions, candidate.features.size());
    stats.feature_dimensions = dimensions;
    std::unordered_set<std::string> keys;
    database.reserve(candidates.size());
    for (const auto &candidate : candidates) {
        std::string reason;
        if (candidate.clip_id.empty()) reason = "empty clip id";
        else if (candidate.features.size() != dimensions) reason = "inconsistent feature dimensions";
        else {
            for (float value : candidate.features) {
                if (!std::isfinite(value)) { reason = "non-finite feature"; break; }
            }
        }
        const std::string key = candidate.clip_id + ":" + std::to_string(candidate.frame);
        if (reason.empty() && !keys.insert(key).second) reason = "duplicate clip/frame";
        if (!reason.empty()) {
            ++stats.rejected_count;
            stats.rejection_reasons.push_back(reason);
            continue;
        }
        database.add(candidate);
        ++stats.accepted_count;
    }
    return stats;
}

const ModuleDescriptor &module_motionquerydatabasebuilder() {
    static const ModuleDescriptor descriptor{
        "MotionQueryDatabaseBuilder", "Deterministic candidate validation and database ingestion."};
    return descriptor;
}

} // namespace motion

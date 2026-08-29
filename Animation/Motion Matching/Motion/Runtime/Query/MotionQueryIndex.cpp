#include "MotionQueryIndex.h"

#include <algorithm>
#include <cmath>
#include <numeric>

namespace motion {

void MotionQueryIndex::rebuild(const MotionQueryDatabase &database) {
    database_ = &database;
    order_.resize(database.size());
    std::iota(order_.begin(), order_.end(), 0);
    std::stable_sort(order_.begin(), order_.end(), [&](std::size_t left, std::size_t right) {
        const MotionCandidate *a = database.get(left);
        const MotionCandidate *b = database.get(right);
        const float af = a && !a->features.empty() ? a->features.front() : 0.0f;
        const float bf = b && !b->features.empty() ? b->features.front() : 0.0f;
        return af < bf;
    });
}

std::vector<std::size_t> MotionQueryIndex::retrieve(const std::vector<float> &query, std::size_t budget) const {
    std::vector<std::size_t> result;
    if (!database_) return result;
    const std::size_t limit = std::min(budget, order_.size());
    result.reserve(limit);
    const float target = query.empty() ? 0.0f : query.front();
    std::vector<std::size_t> ranked = order_;
    std::stable_sort(ranked.begin(), ranked.end(), [&](std::size_t left, std::size_t right) {
        const MotionCandidate *a = database_->get(left);
        const MotionCandidate *b = database_->get(right);
        const float af = a && !a->features.empty() ? std::abs(a->features.front() - target) : INFINITY;
        const float bf = b && !b->features.empty() ? std::abs(b->features.front() - target) : INFINITY;
        return af < bf;
    });
    result.assign(ranked.begin(), ranked.begin() + static_cast<std::ptrdiff_t>(limit));
    return result;
}

bool MotionQueryIndex::empty() const { return order_.empty(); }
std::size_t MotionQueryIndex::indexed_count() const { return order_.size(); }

const ModuleDescriptor &module_motionqueryindex() {
    static const ModuleDescriptor descriptor{
        "MotionQueryIndex", "Deterministic bounded feature index for fast candidate retrieval."};
    return descriptor;
}

} // namespace motion

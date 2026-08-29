#include "MotionQuerySearch.h"

#include <algorithm>
#include <limits>

namespace motion {

SearchResult MotionQuerySearch::execute(const MotionQuery &query, const MotionQueryDatabase &database,
                                        const MotionQueryIndex &index, const MotionMatcher &matcher,
                                        const SearchBudget &budget, const MotionCandidate *fallback) {
    const std::vector<std::size_t> indices = index.retrieve(query.features, budget.max_candidates);
    if (indices.empty()) return matcher.search(query, database, budget, fallback);

    SearchBudget bounded = budget;
    bounded.max_candidates = indices.size();
    return matcher.search_subset(query, database, indices, bounded, fallback);
}

const ModuleDescriptor &module_motionquerysearch() {
    static const ModuleDescriptor descriptor{
        "MotionQuerySearch", "Index-backed bounded retrieval followed by deterministic candidate ranking."};
    return descriptor;
}

} // namespace motion

#pragma once

#include "MotionQueryIndex.h"
#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <cstddef>
#include <vector>

namespace motion {

class MotionQuerySearch {
public:
    static SearchResult execute(const MotionQuery &query, const MotionQueryDatabase &database,
                                const MotionQueryIndex &index, const MotionMatcher &matcher,
                                const SearchBudget &budget, const MotionCandidate *fallback);
};

const ModuleDescriptor &module_motionquerysearch();

} // namespace motion

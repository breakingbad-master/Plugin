#pragma once

#include "MotionQueryDatabase.h"
#include "../Core/MMModule.h"

#include <cstddef>
#include <string>
#include <vector>

namespace motion {

struct MotionQueryDatabaseBuildStats {
    std::size_t input_count = 0;
    std::size_t accepted_count = 0;
    std::size_t rejected_count = 0;
    std::size_t feature_dimensions = 0;
    std::vector<std::string> rejection_reasons;
};

class MotionQueryDatabaseBuilder {
public:
    MotionQueryDatabaseBuildStats build(const std::vector<MotionCandidate> &candidates,
                                        MotionQueryDatabase &database) const;
};

const ModuleDescriptor &module_motionquerydatabasebuilder();

} // namespace motion

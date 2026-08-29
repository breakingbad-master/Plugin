#pragma once

#include "MotionQueryDatabase.h"
#include "../Core/MMModule.h"

#include <cstddef>
#include <vector>

namespace motion {

class MotionQueryIndex {
public:
    void rebuild(const MotionQueryDatabase &database);
    std::vector<std::size_t> retrieve(const std::vector<float> &query, std::size_t budget) const;
    bool empty() const;
    std::size_t indexed_count() const;

private:
    const MotionQueryDatabase *database_ = nullptr;
    std::vector<std::size_t> order_;
};

const ModuleDescriptor &module_motionqueryindex();

} // namespace motion

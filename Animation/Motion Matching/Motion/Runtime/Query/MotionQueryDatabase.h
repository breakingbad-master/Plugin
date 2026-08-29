#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"
#include "MotionQueryFeatureVector.h"

#include <cstddef>
#include <string_view>
#include <vector>

namespace motion {

class MotionQueryDatabase {
public:
    void clear();
    void reserve(std::size_t count);
    std::size_t add(MotionCandidate candidate);
    const MotionCandidate *get(std::size_t index) const;
    std::vector<std::size_t> find_by_tag(std::string_view tag) const;
    std::size_t size() const;
    const std::vector<MotionCandidate> &samples() const;

private:
    std::vector<MotionCandidate> samples_;
};

const ModuleDescriptor &module_motionquerydatabase();

} // namespace motion

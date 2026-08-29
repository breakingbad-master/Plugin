#pragma once

#include "../Core/MMModule.h"

#include <vector>

namespace motion {

class PoseHistoryFeature {
public:
    explicit PoseHistoryFeature(std::size_t capacity = 4);
    void reset();
    void push(std::vector<float> pose);
    std::vector<float> flatten(float decay = 1.0f) const;
    std::size_t size() const;
    std::size_t capacity() const;

private:
    std::size_t capacity_;
    std::vector<std::vector<float>> history_;
};

const ModuleDescriptor &module_posehistoryfeature();

} // namespace motion

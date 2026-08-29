#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <cstddef>
#include <vector>

namespace motion {

class MotionQueryFeatureVector {
public:
    MotionQueryFeatureVector() = default;
    explicit MotionQueryFeatureVector(std::vector<float> values);

    const std::vector<float> &values() const;
    std::size_t size() const;
    float at(std::size_t index) const;
    void normalize(const std::vector<float> &minimum, const std::vector<float> &maximum);
    float squared_distance(const MotionQueryFeatureVector &other, const std::vector<float> &weights = {}) const;

private:
    std::vector<float> values_;
};

const ModuleDescriptor &module_motionqueryfeaturevector();

} // namespace motion

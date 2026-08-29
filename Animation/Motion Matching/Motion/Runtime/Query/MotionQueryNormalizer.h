#pragma once

#include "MotionQueryFeatureVector.h"
#include "../Core/MMModule.h"

#include <vector>

namespace motion {

class MotionQueryNormalizer {
public:
    void fit(const std::vector<std::vector<float>> &samples);
    MotionQueryFeatureVector normalize(const MotionQueryFeatureVector &value) const;
    const std::vector<float> &minimum() const;
    const std::vector<float> &maximum() const;
    bool fitted() const;

private:
    std::vector<float> minimum_;
    std::vector<float> maximum_;
};

const ModuleDescriptor &module_motionquerynormalizer();

} // namespace motion

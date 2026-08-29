#pragma once

#include "MotionQueryFeatureVector.h"
#include "../Core/MMModule.h"

#include <cstddef>
#include <vector>

namespace motion {

class MotionQueryWeightProfile {
public:
    MotionQueryWeightProfile() = default;
    explicit MotionQueryWeightProfile(std::vector<float> weights);

    void set_weights(std::vector<float> weights);
    const std::vector<float> &weights() const;
    std::size_t size() const;
    float weight(std::size_t index) const;
    float distance(const MotionQueryFeatureVector &a, const MotionQueryFeatureVector &b) const;
    bool valid_for(std::size_t dimensions) const;

private:
    std::vector<float> weights_;
};

const ModuleDescriptor &module_motionqueryweightprofile();

} // namespace motion

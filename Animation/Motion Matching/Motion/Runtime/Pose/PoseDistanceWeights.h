#pragma once

#include "../Core/MMModule.h"

#include <cstddef>
#include <vector>

namespace motion {

class PoseDistanceWeights {
public:
    void set_feature_weights(std::vector<float> weights);
    void set_bone_weights(std::vector<float> weights);
    void set_contact_weights(std::vector<float> weights);
    const std::vector<float> &feature_weights() const;
    const std::vector<float> &bone_weights() const;
    const std::vector<float> &contact_weights() const;
    float feature(std::size_t index) const;
    float bone(std::size_t index) const;
    float contact(std::size_t index) const;

private:
    static void sanitize(std::vector<float> &weights);
    std::vector<float> feature_weights_;
    std::vector<float> bone_weights_;
    std::vector<float> contact_weights_;
};

const ModuleDescriptor &module_posedistanceweights();

} // namespace motion

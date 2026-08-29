#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <cstddef>
#include <vector>

namespace motion {

struct PoseBoneSample {
    Vec3 position;
    Vec3 velocity;
    Vec3 angular_velocity;
    bool contact = false;
    float contact_confidence = 0.0f;
};

struct PoseSample {
    std::vector<PoseBoneSample> bones;
    float phase = 0.0f;
    Vec3 root_position;
    Vec3 root_velocity;
};

class PoseFeatureExtractor {
public:
    static std::vector<float> extract(const PoseSample &pose, const std::vector<std::size_t> &bone_indices);
    static std::vector<float> extract_contacts(const PoseSample &pose, const std::vector<std::size_t> &bone_indices);
    static float contact_error(const PoseSample &current, const PoseSample &candidate,
                               const std::vector<std::size_t> &bone_indices);
};

const ModuleDescriptor &module_posefeatureextractor();

} // namespace motion

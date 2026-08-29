#include "PoseFeatureExtractor.h"

#include <algorithm>
#include <cmath>

namespace motion {

std::vector<float> PoseFeatureExtractor::extract(const PoseSample &pose,
                                                 const std::vector<std::size_t> &bone_indices) {
    std::vector<float> features;
    features.reserve(bone_indices.size() * 9 + 6);
    features.insert(features.end(), {pose.root_position.x, pose.root_position.y, pose.root_position.z,
                                     pose.root_velocity.x, pose.root_velocity.y, pose.root_velocity.z});
    for (std::size_t index : bone_indices) {
        if (index >= pose.bones.size()) continue;
        const PoseBoneSample &bone = pose.bones[index];
        features.insert(features.end(), {bone.position.x, bone.position.y, bone.position.z,
                                         bone.velocity.x, bone.velocity.y, bone.velocity.z,
                                         bone.angular_velocity.x, bone.angular_velocity.y, bone.angular_velocity.z});
    }
    features.push_back(pose.phase);
    return features;
}

std::vector<float> PoseFeatureExtractor::extract_contacts(const PoseSample &pose,
                                                          const std::vector<std::size_t> &bone_indices) {
    std::vector<float> contacts;
    contacts.reserve(bone_indices.size() * 2);
    for (std::size_t index : bone_indices) {
        if (index >= pose.bones.size()) {
            contacts.insert(contacts.end(), {0.0f, 0.0f});
            continue;
        }
        const PoseBoneSample &bone = pose.bones[index];
        contacts.push_back(bone.contact ? 1.0f : 0.0f);
        contacts.push_back(std::clamp(bone.contact_confidence, 0.0f, 1.0f));
    }
    return contacts;
}

float PoseFeatureExtractor::contact_error(const PoseSample &current, const PoseSample &candidate,
                                          const std::vector<std::size_t> &bone_indices) {
    float error = 0.0f;
    std::size_t count = 0;
    for (std::size_t index : bone_indices) {
        if (index >= current.bones.size() || index >= candidate.bones.size()) continue;
        const PoseBoneSample &a = current.bones[index];
        const PoseBoneSample &b = candidate.bones[index];
        error += a.contact == b.contact ? 0.0f : 1.0f;
        error += std::abs(a.contact_confidence - b.contact_confidence);
        ++count;
    }
    return count == 0 ? 0.0f : error / static_cast<float>(count);
}

const ModuleDescriptor &module_posefeatureextractor() {
    static const ModuleDescriptor descriptor{
        "PoseFeatureExtractor", "Extracts root, bone, velocity, angular velocity, phase, and contact features."};
    return descriptor;
}

} // namespace motion

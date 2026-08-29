#include "../Runtime/Pose/PoseFeatureExtractor.h"

#include <cassert>
#include <cmath>
#include <iostream>

using namespace motion;

int main() {
    PoseSample current;
    current.root_position = {1.0f, 0.0f, 2.0f};
    current.root_velocity = {3.0f, 0.0f, 0.0f};
    current.phase = 0.25f;
    current.bones.push_back({{0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {}, true, 1.0f});
    current.bones.push_back({{0.0f, 1.0f, 0.0f}, {}, {}, false, 0.2f});

    PoseSample candidate = current;
    candidate.bones[0].contact = false;
    candidate.bones[0].contact_confidence = 0.0f;

    const std::vector<float> features = PoseFeatureExtractor::extract(current, {0, 1});
    assert(features.size() == 25);
    const std::vector<float> contacts = PoseFeatureExtractor::extract_contacts(current, {0, 1, 9});
    assert(contacts.size() == 6);
    assert(std::abs(PoseFeatureExtractor::contact_error(current, candidate, {0, 1}) - 1.0f) < 0.0001f);
    std::cout << "PoseFeatureExtractorTests passed\n";
    return 0;
}

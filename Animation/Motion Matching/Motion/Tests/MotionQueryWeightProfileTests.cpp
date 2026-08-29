#include "../Runtime/Query/MotionQueryWeightProfile.h"

#include <cmath>
#include <iostream>
#include <limits>

using namespace motion;

int main() {
    MotionQueryWeightProfile profile({2.0f, -1.0f, std::numeric_limits<float>::quiet_NaN()});
    if (profile.size() != 3 || profile.weight(0) != 2.0f || profile.weight(1) != 0.0f || profile.weight(2) != 0.0f) return 1;
    if (!profile.valid_for(3) || profile.valid_for(2)) return 1;
    const MotionQueryFeatureVector a({1.0f, 1.0f, 1.0f});
    const MotionQueryFeatureVector b({2.0f, 3.0f, 4.0f});
    if (std::fabs(profile.distance(a, b) - 2.0f) > 0.0001f) return 1;
    MotionQueryWeightProfile defaults;
    if (defaults.weight(99) != 1.0f || !defaults.valid_for(4)) return 1;
    std::cout << "MotionQueryWeightProfileTests passed\n";
    return 0;
}

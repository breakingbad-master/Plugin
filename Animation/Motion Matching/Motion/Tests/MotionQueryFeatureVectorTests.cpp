#include "../Runtime/Query/MotionQueryFeatureVector.h"

#include <cassert>
#include <cmath>
#include <iostream>

using namespace motion;

int main() {
    MotionQueryFeatureVector values({5.0f, 10.0f});
    values.normalize({0.0f, 5.0f}, {10.0f, 15.0f});
    assert(std::abs(values.at(0) - 0.5f) < 0.0001f);
    assert(std::abs(values.at(1) - 0.5f) < 0.0001f);

    MotionQueryFeatureVector target({0.5f, 0.25f});
    const float distance = values.squared_distance(target, {2.0f, 4.0f});
    if (std::abs(distance - 0.25f) >= 0.0001f) return 1;

    MotionQueryFeatureVector different_size({0.5f});
    if (!std::isinf(values.squared_distance(different_size))) return 1;
    std::cout << "MotionQueryFeatureVectorTests passed\n";
    return 0;
}

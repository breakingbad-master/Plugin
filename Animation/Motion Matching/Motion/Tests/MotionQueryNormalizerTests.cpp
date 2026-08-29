#include "../Runtime/Query/MotionQueryNormalizer.h"

#include <iostream>

using namespace motion;

int main() {
    MotionQueryNormalizer normalizer;
    normalizer.fit({{0.0f, 10.0f}, {10.0f, 20.0f}, {5.0f, 15.0f}});
    if (!normalizer.fitted() || normalizer.minimum()[0] != 0.0f || normalizer.maximum()[0] != 10.0f) return 1;
    const MotionQueryFeatureVector normalized = normalizer.normalize(MotionQueryFeatureVector({15.0f, 5.0f}));
    if (normalized.at(0) != 1.0f || normalized.at(1) != 0.0f) return 1;
    MotionQueryNormalizer constant;
    constant.fit({{3.0f}, {3.0f}});
    if (constant.normalize(MotionQueryFeatureVector({99.0f})).at(0) != 0.0f) return 1;
    std::cout << "MotionQueryNormalizerTests passed\n";
    return 0;
}

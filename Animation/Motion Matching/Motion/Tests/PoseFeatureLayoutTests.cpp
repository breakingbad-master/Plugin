#include "../Runtime/Pose/PoseFeatureLayout.h"

#include <iostream>

using namespace motion;

int main() {
    PoseFeatureLayout layout;
    const auto first = layout.add_channel(6);
    const auto second = layout.add_channel(3);
    const auto empty = layout.add_channel(0);
    if (first.offset != 0 || first.dimension != 6 || second.offset != 6 || second.dimension != 3 ||
        empty.offset != 9 || layout.channel_count() != 3 || layout.total_dimension() != 9) return 1;
    if (layout.channel(99).dimension != 0 || layout.channel(99).offset != 9) return 1;
    layout.clear();
    if (layout.channel_count() != 0 || layout.total_dimension() != 0) return 1;
    std::cout << "PoseFeatureLayoutTests passed\n";
    return 0;
}

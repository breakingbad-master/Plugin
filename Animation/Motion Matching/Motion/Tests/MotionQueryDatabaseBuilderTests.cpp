#include "../Runtime/Query/MotionQueryDatabaseBuilder.h"

#include <iostream>
#include <limits>

using namespace motion;

static MotionCandidate candidate(const char *id, std::size_t frame, std::vector<float> features) {
    MotionCandidate value;
    value.clip_id = id;
    value.frame = frame;
    value.features = std::move(features);
    return value;
}

int main() {
    MotionQueryDatabaseBuilder builder;
    MotionQueryDatabase database;
    const std::vector<MotionCandidate> input{
        candidate("walk", 0, {0.0f, 1.0f}),
        candidate("walk", 0, {0.5f, 1.5f}),
        candidate("run", 1, {0.0f}),
        candidate("", 2, {0.0f, 1.0f}),
        candidate("bad", 3, {std::numeric_limits<float>::infinity(), 1.0f})};
    const auto stats = builder.build(input, database);
    if (stats.input_count != 5 || stats.accepted_count != 1 || stats.rejected_count != 4 ||
        stats.feature_dimensions != 2 || database.size() != 1 || stats.rejection_reasons.size() != 4) return 1;
    if (!database.get(0) || database.get(0)->clip_id != "walk") return 1;
    std::cout << "MotionQueryDatabaseBuilderTests passed\n";
    return 0;
}

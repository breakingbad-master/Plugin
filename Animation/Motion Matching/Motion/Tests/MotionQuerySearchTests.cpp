#include "../Runtime/Query/MotionQuerySearch.h"

#include <cassert>
#include <iostream>

using namespace motion;

int main() {
    MotionQueryDatabase database;
    database.add({"slow", 0, {0.1f, 0.0f}, {"locomotion"}, 0.0f, 0.0f});
    database.add({"fast", 1, {0.9f, 0.0f}, {"locomotion"}, 0.0f, 0.0f});
    database.add({"mid", 2, {0.5f, 0.0f}, {"locomotion"}, 0.0f, 0.0f});
    MotionQueryIndex index;
    index.rebuild(database);
    const std::vector<std::size_t> nearest = index.retrieve({0.52f, 0.0f}, 2);
    if (nearest.size() != 2 || database.get(nearest.front())->clip_id != "mid") return 1;

    MotionQuery query;
    query.features = {0.52f, 0.0f};
    query.tags = {"locomotion"};
    MotionCandidate fallback{"idle", 0, {1.0f}, {"idle"}, 0.0f, 0.0f};
    const SearchResult result = MotionQuerySearch::execute(
        query, database, index, MotionMatcher({1.0f, 0.0f, 0.0f, 0.0f}), {2, 2}, &fallback);
    if (!result.selected.candidate || result.selected.candidate->clip_id != "mid") return 1;
    std::cout << "MotionQuerySearchTests passed\n";
    return 0;
}

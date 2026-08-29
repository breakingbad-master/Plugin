#include "../Runtime/Core/MMCore.h"
#include "../Runtime/Query/MotionQueryDatabase.h"

#include <cassert>
#include <cmath>
#include <iostream>

using namespace motion;

int main() {
    MotionQueryDatabase database;
    database.add({"walk_a", 10, {0.0f, 0.0f, 0.0f}, {"locomotion", "walk", "ground"}, 0.0f, 0.0f});
    database.add({"vault_low", 42, {0.1f, 0.1f, 0.1f}, {"traversal", "vault", "ground"}, 1.0f, 0.5f});
    database.add({"vault_high", 45, {0.2f, 0.2f, 0.2f}, {"traversal", "vault", "ground"}, 0.5f, 0.5f});
    MotionCandidate fallback{"idle_fallback", 0, {1.0f, 1.0f, 1.0f}, {"idle"}, 0.0f, 0.0f};

    MotionMatcher matcher({1.0f, 0.0f, 0.0f, 1.0f});
    MotionQuery query;
    query.features = {0.09f, 0.09f, 0.09f};
    query.tags = {"traversal", "vault", "ground"};
    query.environment = {true, true, 0.4f, 0.8f, 0.7f, 0.0f, {0.0f, 1.0f, 0.0f}, "ground"};

    SearchResult result = matcher.search(query, database, {8, 5}, &fallback);
    assert(!result.used_fallback);
    assert(result.selected.candidate->clip_id == "vault_low");
    assert(result.filtered == 2);

    SearchResult budgeted = matcher.search(query, database, {1, 1}, &fallback);
    assert(budgeted.evaluated == 1);

    MotionQuery impossible = query;
    impossible.environment.obstacle_height = 3.0f;
    SearchResult safe = matcher.search(impossible, database, {8, 5}, &fallback);
    assert(safe.used_fallback);
    assert(safe.selected.candidate->clip_id == "idle_fallback");

    std::cout << "MMCoreTests passed\n";
    return 0;
}

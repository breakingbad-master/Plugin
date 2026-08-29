#include "../Runtime/Core/MMRuntimeContext.h"

#include <iostream>

using namespace motion;

int main() {
    MMRuntimeContext context;
    context.budget.max_candidates = 8;
    context.budget.max_results = 2;
    context.root_position = {0.0f, 0.0f, 0.0f};
    context.root_velocity = {1.0f, 0.0f, 0.0f};
    if (!context.valid()) return 1;
    context.advance(1.0f / 60.0f);
    if (context.frame != 1 || context.delta_seconds <= 0.0f) return 1;
    context.budget.max_results = 0;
    if (context.valid()) return 1;
    context.advance(-1.0f);
    if (context.frame != 2 || context.delta_seconds != 0.0f) return 1;
    std::cout << "MMRuntimeContextTests passed\n";
    return 0;
}

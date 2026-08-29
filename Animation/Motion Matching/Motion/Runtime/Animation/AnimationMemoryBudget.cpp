#include "AnimationMemoryBudget.h"

namespace motion {
const ModuleDescriptor &module_animationmemorybudget() {
    static const ModuleDescriptor descriptor{"AnimationMemoryBudget", "Controls animation memory budgets by quality tier."};
    return descriptor;
}
} // namespace motion

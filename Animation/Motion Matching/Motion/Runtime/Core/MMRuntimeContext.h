#pragma once

#include "MMCore.h"
#include "MMModule.h"

#include <cstddef>
#include <cstdint>

namespace motion {

struct MMRuntimeContext {
    std::uint64_t frame = 0;
    std::uint32_t agent_id = 0;
    float delta_seconds = 0.0f;
    SearchBudget budget;
    Vec3 root_position;
    Vec3 root_velocity;
    bool grounded = true;
    bool authoritative_physics = true;

    bool valid() const;
    void advance(float delta);
};

const ModuleDescriptor &module_mmruntimecontext();

} // namespace motion

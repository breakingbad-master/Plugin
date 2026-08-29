#pragma once

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/packed_float32_array.hpp>
#include <godot_cpp/variant/packed_string_array.hpp>

#include "motion_matching_c_api.h"

namespace godot {

class MotionMatchingRuntime : public RefCounted {
    GDCLASS(MotionMatchingRuntime, RefCounted)

private:
    MMRuntimeHandle *runtime_ = nullptr;

protected:
    static void _bind_methods();

public:
    MotionMatchingRuntime();
    ~MotionMatchingRuntime() override;

    void clear_database();
    bool add_candidate(const String &clip_id, int frame, const PackedFloat32Array &features,
                      const PackedStringArray &tags, float max_obstacle_height = 1000000.0f,
                      float min_clearance = 0.0f, float min_speed = 0.0f,
                      float max_speed = 1000000.0f, bool fallback = false);
    Dictionary search(const PackedFloat32Array &features, int frame = 0, bool environment_valid = false,
                      bool environment_blocked = false, float obstacle_distance = 0.0f,
                      float obstacle_height = 0.0f, float clearance = 0.0f,
                      float ground_height = 0.0f, int max_candidates = 256, int max_results = 5) const;
};

} // namespace godot

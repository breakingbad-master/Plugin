#include "motion_matching_godot.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include <algorithm>
#include <limits>
#include <vector>

using namespace godot;

void MotionMatchingRuntime::_bind_methods() {
    ClassDB::bind_method(D_METHOD("clear_database"), &MotionMatchingRuntime::clear_database);
    ClassDB::bind_method(D_METHOD("add_candidate", "clip_id", "frame", "features", "tags",
                                  "max_obstacle_height", "min_clearance", "min_speed", "max_speed", "fallback"),
                         &MotionMatchingRuntime::add_candidate, DEFVAL(1000000.0f), DEFVAL(0.0f), DEFVAL(0.0f),
                         DEFVAL(1000000.0f), DEFVAL(false));
    ClassDB::bind_method(D_METHOD("search", "features", "frame", "environment_valid", "environment_blocked",
                                  "obstacle_distance", "obstacle_height", "clearance", "ground_height",
                                  "max_candidates", "max_results"),
                         &MotionMatchingRuntime::search, DEFVAL(0), DEFVAL(false), DEFVAL(false), DEFVAL(0.0f),
                         DEFVAL(0.0f), DEFVAL(0.0f), DEFVAL(0.0f), DEFVAL(256), DEFVAL(5));
}

MotionMatchingRuntime::MotionMatchingRuntime() : runtime_(mm_runtime_create()) {}
MotionMatchingRuntime::~MotionMatchingRuntime() { mm_runtime_destroy(runtime_); }

void MotionMatchingRuntime::clear_database() {
    if (runtime_) mm_runtime_clear(runtime_);
}

bool MotionMatchingRuntime::add_candidate(const String &clip_id, int frame, const PackedFloat32Array &features,
                                          const PackedStringArray &tags, float max_obstacle_height,
                                          float min_clearance, float min_speed, float max_speed, bool fallback) {
    if (!runtime_ || frame < 0) return false;
    std::vector<float> feature_values;
    feature_values.resize(features.size());
    for (int i = 0; i < features.size(); ++i) feature_values[static_cast<size_t>(i)] = features[i];
    std::vector<CharString> tag_utf8;
    tag_utf8.reserve(tags.size());
    std::vector<const char *> tag_ptrs;
    tag_ptrs.reserve(tags.size());
    for (int i = 0; i < tags.size(); ++i) {
        tag_utf8.push_back(tags[i].utf8());
        tag_ptrs.push_back(tag_utf8.back().get_data());
    }
    const CharString clip_utf8 = clip_id.utf8();
    MMRuntimeCandidateInput input{};
    input.clip_id = clip_utf8.get_data();
    input.frame = static_cast<size_t>(frame);
    input.features = feature_values.data();
    input.feature_count = feature_values.size();
    input.tags = tag_ptrs.data();
    input.tag_count = tag_ptrs.size();
    input.max_obstacle_height = max_obstacle_height;
    input.min_clearance = min_clearance;
    input.min_speed = min_speed;
    input.max_speed = max_speed;
    input.fallback = fallback ? 1 : 0;
    return mm_runtime_add_candidate(runtime_, &input) != 0;
}

Dictionary MotionMatchingRuntime::search(const PackedFloat32Array &features, int frame, bool environment_valid,
                                          bool environment_blocked, float obstacle_distance, float obstacle_height,
                                          float clearance, float ground_height, int max_candidates,
                                          int max_results) const {
    Dictionary output;
    if (!runtime_ || frame < 0 || max_candidates < 0 || max_results < 0) {
        output["ok"] = false;
        return output;
    }
    std::vector<float> values;
    values.resize(features.size());
    for (int i = 0; i < features.size(); ++i) values[static_cast<size_t>(i)] = features[i];
    MMRuntimeQueryInput input{};
    input.features = values.data();
    input.feature_count = values.size();
    input.frame = static_cast<unsigned long long>(frame);
    input.environment_valid = environment_valid ? 1 : 0;
    input.environment_blocked = environment_blocked ? 1 : 0;
    input.obstacle_distance = obstacle_distance;
    input.obstacle_height = obstacle_height;
    input.clearance = clearance;
    input.ground_height = ground_height;
    MMRuntimeSearchOutput result{};
    if (!mm_runtime_search(runtime_, &input, static_cast<size_t>(max_candidates),
                           static_cast<size_t>(max_results), &result)) {
        output["ok"] = false;
        return output;
    }
    output["ok"] = true;
    output["selected_index"] = result.selected_index == SIZE_MAX ? -1 : static_cast<int64_t>(result.selected_index);
    output["selected_score"] = result.selected_score;
    output["evaluated"] = static_cast<int64_t>(result.evaluated);
    output["filtered"] = static_cast<int64_t>(result.filtered);
    output["used_fallback"] = result.used_fallback != 0;
    return output;
}

extern "C" {

GDExtensionBool GDE_EXPORT plugin_library_init(const GDExtensionInterface *interface,
                                               GDExtensionClassLibraryPtr library,
                                               GDExtensionInitialization *initialization) {
    GDExtensionBinding::InitObject init_object(interface, library, initialization);
    init_object.register_initializer([]() { ClassDB::register_class<MotionMatchingRuntime>(); });
    init_object.register_terminator([]() {});
    init_object.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
    return init_object.init();
}

}

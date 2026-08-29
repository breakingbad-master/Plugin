cmake_minimum_required(VERSION 3.20)
project(MotionMatchingCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE MOTION_SOURCES CONFIGURE_DEPENDS
    Motion/*.cpp
)
list(FILTER MOTION_SOURCES EXCLUDE REGEX "/Tests/")

add_library(motion_matching_core STATIC ${MOTION_SOURCES})
add_library(motion_matching_shared SHARED ${MOTION_SOURCES} ../../Plugin/src/motion_matching_c_api.cpp)
set_target_properties(motion_matching_shared PROPERTIES OUTPUT_NAME shared_plugins)
option(MOTION_MATCHING_BUILD_GODOT_ADAPTER "Build the Godot 4 GDExtension wrapper" OFF)
if(MOTION_MATCHING_BUILD_GODOT_ADAPTER)
    if(NOT GODOT_CPP_INCLUDE_DIR OR NOT GODOT_CPP_LIBRARY)
        message(FATAL_ERROR "Set GODOT_CPP_INCLUDE_DIR and GODOT_CPP_LIBRARY to build the Godot adapter")
    endif()
    add_library(shared_plugins_godot SHARED ../../Plugin/src/motion_matching_godot.cpp)
    target_include_directories(shared_plugins_godot PRIVATE
        ../../Plugin/src ${GODOT_CPP_INCLUDE_DIR} Motion/Runtime Motion/Platform)
    target_link_libraries(shared_plugins_godot PRIVATE motion_matching_shared ${GODOT_CPP_LIBRARY})
    set_target_properties(shared_plugins_godot PROPERTIES OUTPUT_NAME shared_plugins)
endif()
foreach(runtime_target IN ITEMS motion_matching_core motion_matching_shared)
    target_include_directories(${runtime_target} PUBLIC Motion/Runtime Motion/Platform)
    target_compile_options(${runtime_target} PRIVATE -Wall -Wextra -Wpedantic)
endforeach()

enable_testing()
foreach(test_name IN ITEMS MMCoreTests MotionTrajectoryTests MotionMatchingCollisionTests MotionQueryFeatureVectorTests PoseFeatureExtractorTests AnimationChooserTests MotionWarpingSolverTests TraversalSystemTests MotionQueryDatabaseSerializerTests MotionQuerySearchTests MMFrameCacheTests MMRuntimeContextTests MotionQueryNormalizerTests MotionQueryWeightProfileTests MotionQuerySearchCacheTests MotionQueryProfileTests MotionQueryDatabaseBuilderTests PoseBoneFeatureTests PoseVelocityFeatureTests PoseAngularVelocityFeatureTests PoseContactFeatureTests PosePhaseFeatureTests PoseHistoryFeatureTests PoseRelativeFeatureTests PoseTrajectoryFeatureTests PoseRootFeatureTests PoseAccelerationFeatureTests PoseDistanceMetricTests PoseDistanceWeightsTests PoseContactScorerTests PoseContinuityScorerTests PosePhaseScorerTests)
    add_executable(${test_name} Motion/Tests/${test_name}.cpp)
    target_link_libraries(${test_name} PRIVATE motion_matching_core)
    target_compile_options(${test_name} PRIVATE -Wall -Wextra -Wpedantic)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()

add_executable(MotionRuntimeCapiTests ../../Plugin/tests/motion_matching_c_api_tests.cpp ../../Plugin/src/motion_matching_c_api.cpp)
target_include_directories(MotionRuntimeCapiTests PRIVATE ../../Plugin/src Motion/Runtime Motion/Platform)
target_link_libraries(MotionRuntimeCapiTests PRIVATE motion_matching_core)
target_compile_options(MotionRuntimeCapiTests PRIVATE -Wall -Wextra -Wpedantic)
add_test(NAME MotionRuntimeCapiTests COMMAND MotionRuntimeCapiTests)

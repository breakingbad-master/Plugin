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
foreach(runtime_target IN ITEMS motion_matching_core motion_matching_shared)
    target_include_directories(${runtime_target} PUBLIC Motion/Runtime Motion/Platform)
    target_compile_options(${runtime_target} PRIVATE -Wall -Wextra -Wpedantic)
endforeach()

enable_testing()
foreach(test_name IN ITEMS MMCoreTests MotionTrajectoryTests MotionMatchingCollisionTests MotionQueryFeatureVectorTests PoseFeatureExtractorTests AnimationChooserTests MotionWarpingSolverTests TraversalSystemTests MotionQueryDatabaseSerializerTests MotionQuerySearchTests MMFrameCacheTests MMRuntimeContextTests MotionQueryNormalizerTests MotionQueryWeightProfileTests)
    add_executable(${test_name} Motion/Tests/${test_name}.cpp)
    target_link_libraries(${test_name} PRIVATE motion_matching_core)
    target_compile_options(${test_name} PRIVATE -Wall -Wextra -Wpedantic)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()

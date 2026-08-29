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
target_include_directories(motion_matching_core PUBLIC Motion/Runtime Motion/Platform)
target_compile_options(motion_matching_core PRIVATE -Wall -Wextra -Wpedantic)

enable_testing()
foreach(test_name IN ITEMS MMCoreTests MotionTrajectoryTests MotionMatchingCollisionTests MotionQueryFeatureVectorTests PoseFeatureExtractorTests AnimationChooserTests MotionWarpingSolverTests TraversalSystemTests MotionQueryDatabaseSerializerTests MotionQuerySearchTests MMFrameCacheTests)
    add_executable(${test_name} Motion/Tests/${test_name}.cpp)
    target_link_libraries(${test_name} PRIVATE motion_matching_core)
    target_compile_options(${test_name} PRIVATE -Wall -Wextra -Wpedantic)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()

# Motion Matching status

This is the first functional implementation slice from the production blueprint. It is intentionally focused on correctness and deterministic behavior before adding the larger editor and engine integration layers.

## Implemented

| Capability | Implementation |
|---|---|
| General motion query | Packed feature vector, tags, trajectory, frame identity |
| Candidate search | Bounded database scan, stable score ordering, top-N results |
| Scoring | Feature, trajectory, contact, and continuity costs with configurable weights |
| Safe fallback | Returns an explicit fallback candidate when no valid candidate survives |
| Environment awareness | Obstacle height, clearance, surface tag, ground height, and validity flags |
| Predictive collision | Forward/top/landing probes and traversal candidate validation |
| Trajectory refinement | Ground projection, speed constraint, landing-distance clamp, capability checks |
| Android policy | Low/medium/high quality tiers with bounded query, sample, memory, and debug budgets |
| Query normalization | Fitted per-dimension min/max normalization with safe constant-range handling |
| Query weights | Sanitized per-dimension weights and weighted distance helper |
| Query search cache | Bounded LRU cache with exact frame/feature keys and invalidation |
| Query profiling | Timing, worst-case, evaluated/filtered, and cache-hit metrics |
| Database builder | Deterministic candidate validation and rejection diagnostics |
| Pose features | Bone, linear velocity, angular velocity, contact, phase, and bounded history encoders |
| Shared runtime ABI | Opaque C ABI bridge and direct end-to-end bridge test |
| Godot integration boundary | Godot 4 `MotionMatchingRuntime` wrapper source with opt-in CMake target |
| Shared library and CI | `libshared_plugins.so` target plus desktop and Android arm64 workflow using NDK 23.2.8568313 |
| Tests | Core, query, pose, ABI, and integration regression coverage |

## Validation

From this directory:

```bash
cmake -S . -B build-cmake -DCMAKE_BUILD_TYPE=Release
cmake --build build-cmake --parallel 2
ctest --test-dir build-cmake --output-on-failure
```

The current Release suite passes **24/24 tests**. The core/shared runtime builds locally, produces `libshared_plugins.so`, and the Android arm64 build is wired into GitHub Actions. The Godot wrapper source is present behind an opt-in CMake target that requires a godot-cpp build; the next validation step is compiling that target with the exact Godot 4/godot-cpp Android toolchain.

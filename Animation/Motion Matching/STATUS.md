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
| Tests | Core ranking/fallback, trajectory refinement, and collision/traversal rejection |

## Validation

From this directory:

```bash
cmake -S . -B build-cmake -DCMAKE_BUILD_TYPE=Release
cmake --build build-cmake --parallel 2
ctest --test-dir build-cmake --output-on-failure
```

The current test suite passes all three tests. The next implementation slice should add clip ingestion/serialization, pose feature extraction, chooser/variant cooldowns, constrained warping, interaction/traversal resolvers, and the Godot GDExtension adapter. Those layers will consume the current data-oriented interfaces rather than replacing them.

# Motion Matching implementation

This folder follows the production blueprint while keeping the engine-independent runtime separate from the Godot adapter.

## Implemented first milestone

The first milestone is a deterministic, data-oriented search core. It represents a general motion query, packed feature vectors, trajectory/environment context, tagged candidates, candidate filtering, weighted pose/trajectory/contact/continuity scoring, bounded candidate budgets, safe fallback, and a small runtime coordinator. The core has no Godot dependency and can therefore be tested on desktop before being exposed through GDExtension.

| Area | Location | Responsibility |
|---|---|---|
| Core runtime | `Motion/Runtime/Core/` | budgets, deterministic runtime state, validation |
| Query/search | `Motion/Runtime/Query/` | query vector, candidate database, ranking and fallback |
| Pose features | `Motion/Runtime/Pose/` | packed pose/contact/phase feature data |
| Trajectory | `Motion/Runtime/Trajectory/` | future samples and environment-aware refinement |
| Godot adapter | `Motion/Platform/Godot/` | later GDExtension boundary; no editor dependency in runtime |
| Mobile policy | `Motion/Platform/Mobile/` | fixed budgets and update frequency policy |
| Tests | `Motion/Tests/` | deterministic unit and regression coverage |

## Decision pipeline

`Current state -> query build -> environment probe -> candidate filter -> bounded search -> continuity/contact scoring -> selected frame -> trajectory refinement -> constrained playback/fallback`.

Physics remains authoritative. The motion environment is read-only and predictive. A candidate is rejected when its tags, obstacle capability, clearance, or budget constraints are invalid. When every candidate is invalid, the runtime returns a declared fallback frame instead of leaving the character without a valid pose.

## Increment plan

The next increments add animation clip ingestion/serialization, chooser and variant cooldowns, warping profiles, interaction/traversal candidate generation, editor debugger data, and finally the Godot/Android adapter. The 220-file blueprint is treated as a production boundary map; files are implemented in cohesive slices rather than generated as empty stubs.

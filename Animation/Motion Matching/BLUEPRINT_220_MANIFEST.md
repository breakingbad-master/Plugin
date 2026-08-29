# 220 C++ implementation manifest

| # | Module | Source directory | Responsibility |
|---:|---|---|---|
| 001 | `MMSystem.h/.cpp` | `Runtime/Core/` | Main runtime coordinator for motion-matching evaluation, lifecycle, and integration. |
| 002 | `MMRuntimeContext.h/.cpp` | `Runtime/Core/` | Per-frame context shared by search, scoring, pose, trajectory, and playback. |
| 003 | `MMUpdateScheduler.h/.cpp` | `Runtime/Core/` | Schedules animation evaluation at configurable frequencies for mobile performance. |
| 004 | `MMThreading.h/.cpp` | `Runtime/Core/` | Threading policy and worker orchestration for background query/search work. |
| 005 | `MMJobSystem.h/.cpp` | `Runtime/Core/` | Small jobs for feature extraction, candidate scoring, and database queries. |
| 006 | `MMFrameCache.h/.cpp` | `Runtime/Core/` | Caches reusable frame/query data to reduce repeated work. |
| 007 | `MMTimeContext.h/.cpp` | `Runtime/Core/` | Normalized animation and simulation time utilities. |
| 008 | `MMDeterminism.h/.cpp` | `Runtime/Core/` | Deterministic evaluation support for reproducible tests and networking. |
| 009 | `MMConfig.h/.cpp` | `Runtime/Core/` | Runtime/editor configuration for quality tiers and feature switches. |
| 010 | `MMValidation.h/.cpp` | `Runtime/Core/` | Runtime assertions and validation for malformed animation/query data. |
| 011 | `MotionQuery.h/.cpp` | `Runtime/Query/` | Base query representation that can describe any animation intent, not locomotion only. |
| 012 | `MotionQueryBuilder.h/.cpp` | `Runtime/Query/` | Builds queries from gameplay state, pose, trajectory, contacts, and tags. |
| 013 | `MotionQueryContext.h/.cpp` | `Runtime/Query/` | Context passed into query generation and feature extraction. |
| 014 | `MotionQueryFeature.h/.cpp` | `Runtime/Query/` | Base feature interface for searchable motion information. |
| 015 | `MotionQueryFeatureVector.h/.cpp` | `Runtime/Query/` | Packed numeric feature vector for fast comparisons. |
| 016 | `MotionQueryFeatureExtractor.h/.cpp` | `Runtime/Query/` | Extracts searchable features from current state and target intent. |
| 017 | `MotionQueryNormalizer.h/.cpp` | `Runtime/Query/` | Normalizes feature ranges before distance scoring. |
| 018 | `MotionQueryWeightProfile.h/.cpp` | `Runtime/Query/` | Configurable weights for different feature dimensions. |
| 019 | `MotionQueryDatabase.h/.cpp` | `Runtime/Query/` | Runtime searchable collection of motion samples. |
| 020 | `MotionQueryDatabaseBuilder.h/.cpp` | `Runtime/Query/` | Builds databases from animation clips and sampled poses. |
| 021 | `MotionQueryDatabaseSerializer.h/.cpp` | `Runtime/Query/` | Loads/saves database data efficiently. |
| 022 | `MotionQueryIndex.h/.cpp` | `Runtime/Query/` | Index over samples for faster candidate retrieval. |
| 023 | `MotionQuerySearch.h/.cpp` | `Runtime/Query/` | Executes candidate retrieval and ranking. |
| 024 | `MotionQuerySearchBatch.h/.cpp` | `Runtime/Query/` | Batched search for multiple agents. |
| 025 | `MotionQuerySearchCache.h/.cpp` | `Runtime/Query/` | Caches repeated queries and nearby results. |
| 026 | `MotionQueryCandidate.h/.cpp` | `Runtime/Query/` | Represents one searchable animation sample candidate. |
| 027 | `MotionQueryCandidateFilter.h/.cpp` | `Runtime/Query/` | Rejects invalid, incompatible, or gameplay-blocked candidates. |
| 028 | `MotionQueryCostModel.h/.cpp` | `Runtime/Query/` | Measures and limits search cost on mobile. |
| 029 | `MotionQueryDebug.h/.cpp` | `Runtime/Query/` | Debug visualization and statistics for query construction. |
| 030 | `MotionQueryProfile.h/.cpp` | `Runtime/Query/` | Captures query timings and quality metrics. |
| 031 | `MotionQueryReplay.h/.cpp` | `Runtime/Query/` | Records queries/results for regression testing. |
| 032 | `PoseFeature.h/.cpp` | `Runtime/Pose/` | Base interface for pose-derived matching features. |
| 033 | `PoseFeatureExtractor.h/.cpp` | `Runtime/Pose/` | Extracts pose information from the active character. |
| 034 | `PoseBoneFeature.h/.cpp` | `Runtime/Pose/` | Bone-position/orientation feature. |
| 035 | `PoseVelocityFeature.h/.cpp` | `Runtime/Pose/` | Bone velocity feature for motion continuity. |
| 036 | `PoseAccelerationFeature.h/.cpp` | `Runtime/Pose/` | Bone acceleration feature for impact and dynamic matching. |
| 037 | `PoseAngularVelocityFeature.h/.cpp` | `Runtime/Pose/` | Angular velocity feature for rotations. |
| 038 | `PoseContactFeature.h/.cpp` | `Runtime/Pose/` | Foot/hand/body contact state feature. |
| 039 | `PosePhaseFeature.h/.cpp` | `Runtime/Pose/` | Animation phase feature for cyclic or repeated motion. |
| 040 | `PoseHistoryFeature.h/.cpp` | `Runtime/Pose/` | Short pose-history feature for continuity. |
| 041 | `PoseTrajectoryFeature.h/.cpp` | `Runtime/Pose/` | Future trajectory feature for matching movement intent. |
| 042 | `PoseRootFeature.h/.cpp` | `Runtime/Pose/` | Root transform and velocity feature. |
| 043 | `PoseRelativeFeature.h/.cpp` | `Runtime/Pose/` | Relative transforms between important bones. |
| 044 | `PoseFeatureLayout.h/.cpp` | `Runtime/Pose/` | Defines packed feature memory layout. |
| 045 | `PoseFeatureCache.h/.cpp` | `Runtime/Pose/` | Caches extracted pose features. |
| 046 | `PoseFeatureCompression.h/.cpp` | `Runtime/Pose/` | Quantizes/compresses features for memory efficiency. |
| 047 | `PoseDistanceMetric.h/.cpp` | `Runtime/Pose/` | Distance calculation between query and candidate features. |
| 048 | `PoseDistanceWeights.h/.cpp` | `Runtime/Pose/` | Per-feature and per-bone scoring weights. |
| 049 | `PoseContinuityScorer.h/.cpp` | `Runtime/Pose/` | Penalizes visually bad transitions. |
| 050 | `PoseContactScorer.h/.cpp` | `Runtime/Pose/` | Scores contact consistency. |
| 051 | `PosePhaseScorer.h/.cpp` | `Runtime/Pose/` | Scores cyclic phase continuity. |
| 052 | `MotionTrajectory.h/.cpp` | `Runtime/Trajectory/` | General future trajectory representation for characters and objects. |
| 053 | `TrajectorySampler.h/.cpp` | `Runtime/Trajectory/` | Samples future positions, rotations, and velocities. |
| 054 | `TrajectoryPredictor.h/.cpp` | `Runtime/Trajectory/` | Predicts intended movement from input and gameplay state. |
| 055 | `TrajectoryProjector.h/.cpp` | `Runtime/Trajectory/` | Projects trajectory against navigation/ground constraints. |
| 056 | `TrajectorySmoother.h/.cpp` | `Runtime/Trajectory/` | Removes noisy input and prediction changes. |
| 057 | `TrajectoryResampler.h/.cpp` | `Runtime/Trajectory/` | Resamples trajectory at fixed time intervals. |
| 058 | `TrajectoryNormalizer.h/.cpp` | `Runtime/Trajectory/` | Normalizes trajectory features for matching. |
| 059 | `TrajectoryFeatureExtractor.h/.cpp` | `Runtime/Trajectory/` | Creates searchable trajectory features. |
| 060 | `TrajectoryDebugDraw.h/.cpp` | `Runtime/Trajectory/` | Visualizes future path and sampled points. |
| 061 | `TrajectoryHistory.h/.cpp` | `Runtime/Trajectory/` | Stores recent trajectory history. |
| 062 | `TrajectoryConstraint.h/.cpp` | `Runtime/Trajectory/` | Applies speed, turn, slope, and gameplay constraints. |
| 063 | `AnimationLibrary.h/.cpp` | `Runtime/Animation/` | Runtime registry for all animation assets and clips. |
| 064 | `AnimationClipDatabase.h/.cpp` | `Runtime/Animation/` | Metadata and lookup for animation clips. |
| 065 | `AnimationClipSampler.h/.cpp` | `Runtime/Animation/` | Samples arbitrary clips into searchable frames. |
| 066 | `AnimationTagSystem.h/.cpp` | `Runtime/Animation/` | Tags animations by action, stance, context, surface, and gameplay use. |
| 067 | `AnimationVariantResolver.h/.cpp` | `Runtime/Animation/` | Selects among multiple variants instead of assuming one clip. |
| 068 | `AnimationSet.h/.cpp` | `Runtime/Animation/` | Groups related clips for a character or feature. |
| 069 | `AnimationSetResolver.h/.cpp` | `Runtime/Animation/` | Resolves the correct set from runtime context. |
| 070 | `LocomotionLibrary.h/.cpp` | `Runtime/Animation/` | Locomotion-specific library built on the general animation system. |
| 071 | `LocomotionState.h/.cpp` | `Runtime/Animation/` | Runtime locomotion state representation. |
| 072 | `LocomotionTransition.h/.cpp` | `Runtime/Animation/` | Transition rules between movement states. |
| 073 | `LocomotionChooser.h/.cpp` | `Runtime/Animation/` | Chooses suitable locomotion variants. |
| 074 | `AnimationMover.h/.cpp` | `Runtime/Animation/` | Moves character motion according to animation/root-motion policy. |
| 075 | `MoverState.h/.cpp` | `Runtime/Animation/` | Runtime movement state used by animation and gameplay. |
| 076 | `MoverConstraint.h/.cpp` | `Runtime/Animation/` | Applies movement limits and gameplay constraints. |
| 077 | `MoverExampleController.h/.cpp` | `Runtime/Animation/` | Reference controller demonstrating integration. |
| 078 | `AnimationLibraryStreaming.h/.cpp` | `Runtime/Animation/` | Streams animation data on demand. |
| 079 | `AnimationMemoryBudget.h/.cpp` | `Runtime/Animation/` | Controls animation memory budgets by quality tier. |
| 080 | `AnimationLODPolicy.h/.cpp` | `Runtime/Animation/` | Reduces animation workload based on distance/importance. |
| 081 | `AnimationChooser.h/.cpp` | `Runtime/Chooser/` | General-purpose animation selection layer for any action. |
| 082 | `AnimationChooserRule.h/.cpp` | `Runtime/Chooser/` | Rule describing a valid selection condition. |
| 083 | `AnimationChooserContext.h/.cpp` | `Runtime/Chooser/` | Runtime context supplied to chooser rules. |
| 084 | `AnimationChooserScore.h/.cpp` | `Runtime/Chooser/` | Scores candidate animations. |
| 085 | `AnimationChooserFallback.h/.cpp` | `Runtime/Chooser/` | Safe fallback when no ideal animation exists. |
| 086 | `AnimationChooserVariant.h/.cpp` | `Runtime/Chooser/` | Variant selection for repeated actions. |
| 087 | `AnimationChooserCooldown.h/.cpp` | `Runtime/Chooser/` | Prevents undesirable immediate repetition. |
| 088 | `AnimationChooserHistory.h/.cpp` | `Runtime/Chooser/` | Tracks recent selections. |
| 089 | `AnimationChooserDebug.h/.cpp` | `Runtime/Chooser/` | Explains why an animation was selected. |
| 090 | `AnimationChooserProfile.h/.cpp` | `Runtime/Chooser/` | Tunable selection profiles. |
| 091 | `MotionWarpingSystem.h/.cpp` | `Runtime/Warping/` | Coordinates target-aware motion warping. |
| 092 | `MotionWarpingTarget.h/.cpp` | `Runtime/Warping/` | Describes a target transform for an animation. |
| 093 | `MotionWarpingWindow.h/.cpp` | `Runtime/Warping/` | Defines where warping is allowed in a clip. |
| 094 | `MotionWarpingModifier.h/.cpp` | `Runtime/Warping/` | Base interface for a warp operation. |
| 095 | `MotionWarpingTranslation.h/.cpp` | `Runtime/Warping/` | Translation correction. |
| 096 | `MotionWarpingRotation.h/.cpp` | `Runtime/Warping/` | Rotation correction. |
| 097 | `MotionWarpingScale.h/.cpp` | `Runtime/Warping/` | Optional constrained scale correction. |
| 098 | `MotionWarpingConstraint.h/.cpp` | `Runtime/Warping/` | Limits warp magnitude and axis behavior. |
| 099 | `MotionWarpingSolver.h/.cpp` | `Runtime/Warping/` | Solves target alignment. |
| 100 | `MotionWarpingBlend.h/.cpp` | `Runtime/Warping/` | Blends warp influence smoothly. |
| 101 | `MotionWarpingDebug.h/.cpp` | `Runtime/Warping/` | Visualizes targets and correction. |
| 102 | `AnimationWarpingSystem.h/.cpp` | `Runtime/Warping/` | General animation-space deformation/adjustment system. |
| 103 | `AnimationWarpingModifier.h/.cpp` | `Runtime/Warping/` | Base modifier for non-locomotion animation warping. |
| 104 | `AnimationWarpingFoot.h/.cpp` | `Runtime/Warping/` | Foot placement correction. |
| 105 | `AnimationWarpingHand.h/.cpp` | `Runtime/Warping/` | Hand placement correction. |
| 106 | `AnimationWarpingBody.h/.cpp` | `Runtime/Warping/` | Body alignment correction. |
| 107 | `AnimationWarpingContact.h/.cpp` | `Runtime/Warping/` | Contact-driven correction. |
| 108 | `AnimationWarpingBlend.h/.cpp` | `Runtime/Warping/` | Blends multiple warping influences. |
| 109 | `AnimationWarpingProfile.h/.cpp` | `Runtime/Warping/` | Reusable warp configuration. |
| 110 | `AnimationWarpingDebug.h/.cpp` | `Runtime/Warping/` | Debug visualization for animation warping. |
| 111 | `AnimationCurve.h/.cpp` | `Runtime/Animation/` | Generic animation curve representation. |
| 112 | `AnimationCurveSampler.h/.cpp` | `Runtime/Animation/` | Samples curves efficiently. |
| 113 | `AnimationCurveRemapping.h/.cpp` | `Runtime/Animation/` | Maps source curve ranges to destination ranges. |
| 114 | `AnimationCurveNormalizer.h/.cpp` | `Runtime/Animation/` | Normalizes curve values. |
| 115 | `AnimationCurveEvaluator.h/.cpp` | `Runtime/Animation/` | Runtime curve evaluation. |
| 116 | `AnimationCurveBlender.h/.cpp` | `Runtime/Animation/` | Blends multiple curves. |
| 117 | `AnimationCurveCompressor.h/.cpp` | `Runtime/Animation/` | Compresses curve keys for memory. |
| 118 | `AnimationCurveEvent.h/.cpp` | `Runtime/Animation/` | Curve-driven event markers. |
| 119 | `AnimationCurveProfile.h/.cpp` | `Runtime/Animation/` | Reusable curve settings. |
| 120 | `AnimationCurveDebug.h/.cpp` | `Runtime/Animation/` | Curve inspection and visualization. |
| 121 | `GameplayInteractionSystem.h/.cpp` | `Runtime/Interaction/` | General interaction framework for characters, props, and gameplay actions. |
| 122 | `GameplayInteractionQuery.h/.cpp` | `Runtime/Interaction/` | Finds compatible interaction opportunities. |
| 123 | `GameplayInteractionTarget.h/.cpp` | `Runtime/Interaction/` | Represents a target actor/object. |
| 124 | `GameplayInteractionContext.h/.cpp` | `Runtime/Interaction/` | Runtime context for interaction selection. |
| 125 | `GameplayInteractionResolver.h/.cpp` | `Runtime/Interaction/` | Resolves the best compatible interaction. |
| 126 | `GameplayInteractionSlot.h/.cpp` | `Runtime/Interaction/` | Defines an interaction position/orientation. |
| 127 | `GameplayInteractionAlignment.h/.cpp` | `Runtime/Interaction/` | Aligns participants before animation. |
| 128 | `GameplayInteractionReservation.h/.cpp` | `Runtime/Interaction/` | Prevents two agents claiming one interaction. |
| 129 | `GameplayInteractionState.h/.cpp` | `Runtime/Interaction/` | Tracks interaction lifecycle. |
| 130 | `GameplayInteractionMontage.h/.cpp` | `Runtime/Interaction/` | Coordinates multi-stage interaction animation. |
| 131 | `GameplayInteractionCancel.h/.cpp` | `Runtime/Interaction/` | Safe interruption and recovery. |
| 132 | `GameplayInteractionBlend.h/.cpp` | `Runtime/Interaction/` | Blends into/out of interactions. |
| 133 | `TakedownSystem.h/.cpp` | `Runtime/Interaction/` | Specialized takedown layer using the general interaction framework. |
| 134 | `TakedownQuery.h/.cpp` | `Runtime/Interaction/` | Finds valid takedown candidates. |
| 135 | `TakedownTargeting.h/.cpp` | `Runtime/Interaction/` | Determines attacker/target alignment. |
| 136 | `TakedownAlignment.h/.cpp` | `Runtime/Interaction/` | Aligns attacker and victim. |
| 137 | `TakedownAnimationResolver.h/.cpp` | `Runtime/Interaction/` | Selects takedown variants. |
| 138 | `TakedownWarp.h/.cpp` | `Runtime/Interaction/` | Warps takedown animation to target. |
| 139 | `TakedownState.h/.cpp` | `Runtime/Interaction/` | Tracks takedown phases. |
| 140 | `TakedownRecovery.h/.cpp` | `Runtime/Interaction/` | Returns both characters to valid states. |
| 141 | `ShoveSystem.h/.cpp` | `Runtime/Interaction/` | General shove interaction. |
| 142 | `TackleSystem.h/.cpp` | `Runtime/Interaction/` | General tackle interaction. |
| 143 | `BenchInteraction.h/.cpp` | `Runtime/Interaction/` | Bench sit/stand and contextual interaction example. |
| 144 | `SmartObjectSystem.h/.cpp` | `Runtime/Interaction/` | Registry and runtime manager for contextual world interactions. |
| 145 | `SmartObjectDefinition.h/.cpp` | `Runtime/Interaction/` | Defines an object's interaction capabilities. |
| 146 | `SmartObjectComponent.h/.cpp` | `Runtime/Interaction/` | Runtime component attached to an object. |
| 147 | `SmartObjectSlot.h/.cpp` | `Runtime/Interaction/` | Interaction slot and transform. |
| 148 | `SmartObjectQuery.h/.cpp` | `Runtime/Interaction/` | Finds compatible objects. |
| 149 | `SmartObjectClaim.h/.cpp` | `Runtime/Interaction/` | Reserves an object slot. |
| 150 | `SmartObjectRelease.h/.cpp` | `Runtime/Interaction/` | Releases a claim safely. |
| 151 | `SmartObjectCondition.h/.cpp` | `Runtime/Interaction/` | Context conditions for availability. |
| 152 | `SmartObjectBehavior.h/.cpp` | `Runtime/Interaction/` | Behavior selected after claiming. |
| 153 | `SmartObjectAnimationResolver.h/.cpp` | `Runtime/Interaction/` | Maps smart-object states to animations. |
| 154 | `SmartObjectWarp.h/.cpp` | `Runtime/Interaction/` | Aligns characters to object slots. |
| 155 | `SmartObjectDebug.h/.cpp` | `Runtime/Interaction/` | Visualizes slots, claims, and state. |
| 156 | `TraversalSystem.h/.cpp` | `Runtime/Traversal/` | General traversal framework, independent of locomotion. |
| 157 | `TraversalQuery.h/.cpp` | `Runtime/Traversal/` | Detects possible traversal opportunities. |
| 158 | `TraversalProbe.h/.cpp` | `Runtime/Traversal/` | Performs geometry probes for traversal. |
| 159 | `TraversalCandidate.h/.cpp` | `Runtime/Traversal/` | Represents one traversal solution. |
| 160 | `TraversalScorer.h/.cpp` | `Runtime/Traversal/` | Ranks traversal candidates. |
| 161 | `TraversalAlignment.h/.cpp` | `Runtime/Traversal/` | Aligns character before traversal. |
| 162 | `TraversalWarp.h/.cpp` | `Runtime/Traversal/` | Corrects animation to geometry. |
| 163 | `TraversalState.h/.cpp` | `Runtime/Traversal/` | Traversal phase state machine. |
| 164 | `TraversalRecovery.h/.cpp` | `Runtime/Traversal/` | Handles failed/interrupted traversal. |
| 165 | `CatchTraversal.h/.cpp` | `Runtime/Traversal/` | Catch/fall recovery traversal. |
| 166 | `ClimbTraversal.h/.cpp` | `Runtime/Traversal/` | Climb action logic. |
| 167 | `HurdleTraversal.h/.cpp` | `Runtime/Traversal/` | Hurdle action logic. |
| 168 | `MantleTraversal.h/.cpp` | `Runtime/Traversal/` | Mantle action logic. |
| 169 | `VaultTraversal.h/.cpp` | `Runtime/Traversal/` | Vault action logic. |
| 170 | `JumpTraversal.h/.cpp` | `Runtime/Traversal/` | Jump traversal logic. |
| 171 | `JumpTakeoff.h/.cpp` | `Runtime/Traversal/` | Jump-off/takeoff phase handling. |
| 172 | `JumpLand.h/.cpp` | `Runtime/Traversal/` | Landing phase handling. |
| 173 | `TraversalAnimationResolver.h/.cpp` | `Runtime/Traversal/` | Selects traversal variants. |
| 174 | `TraversalDebug.h/.cpp` | `Runtime/Traversal/` | Traversal probes and result visualization. |
| 175 | `IdleSystem.h/.cpp` | `Runtime/Animation/` | General idle selection supporting many idle variants. |
| 176 | `IdleVariantResolver.h/.cpp` | `Runtime/Animation/` | Chooses idle based on context/history. |
| 177 | `IdleBreakSystem.h/.cpp` | `Runtime/Animation/` | Breaks idle with contextual micro-actions. |
| 178 | `IdleTransition.h/.cpp` | `Runtime/Animation/` | Transitions into and out of idle. |
| 179 | `LookAtPOISystem.h/.cpp` | `Runtime/Animation/` | Look-at points of interest system. |
| 180 | `LookAtPOITarget.h/.cpp` | `Runtime/Animation/` | Represents a point of interest. |
| 181 | `LookAtPOIResolver.h/.cpp` | `Runtime/Animation/` | Selects the best target. |
| 182 | `LookAtPOISolver.h/.cpp` | `Runtime/Animation/` | Solves head/eye/body orientation. |
| 183 | `LookAtPOIBlend.h/.cpp` | `Runtime/Animation/` | Blends look-at influence. |
| 184 | `RagdollSystem.h/.cpp` | `Runtime/Animation/` | Runtime ragdoll activation and recovery. |
| 185 | `RagdollBlend.h/.cpp` | `Runtime/Animation/` | Blends ragdoll back into animation. |
| 186 | `RagdollPoseMatcher.h/.cpp` | `Runtime/Animation/` | Finds a suitable recovery pose. |
| 187 | `RagdollRecovery.h/.cpp` | `Runtime/Animation/` | Returns from ragdoll to valid animation. |
| 188 | `ActionAnimationSystem.h/.cpp` | `Runtime/Animation/` | Generic action animation orchestration. |
| 189 | `ActionVariantResolver.h/.cpp` | `Runtime/Animation/` | Selects variants for generic actions. |
| 190 | `ActionCooldown.h/.cpp` | `Runtime/Animation/` | Controls repeated actions. |
| 191 | `ActionState.h/.cpp` | `Runtime/Animation/` | Generic action state tracking. |
| 192 | `MotionMatchingEditor.h/.cpp` | `Editor/` | Editor module for authoring and inspecting motion matching. |
| 193 | `MotionMatchingEditorPanel.h/.cpp` | `Editor/` | Main editor panel. |
| 194 | `MotionMatchingEditorToolbar.h/.cpp` | `Editor/` | Editor controls and quality/debug controls. |
| 195 | `MotionMatchingEditorSettings.h/.cpp` | `Editor/` | Persistent editor settings. |
| 196 | `MotionMatchingViewport.h/.cpp` | `Editor/` | Dedicated viewport for motion matching assets. |
| 197 | `MotionMatchingViewportCamera.h/.cpp` | `Editor/` | Viewport camera controls. |
| 198 | `MotionMatchingViewportGrid.h/.cpp` | `Editor/` | 3D grid and scale visualization. |
| 199 | `MotionMatchingViewportGizmo.h/.cpp` | `Editor/` | Transform/navigation gizmo. |
| 200 | `MotionMatchingViewportEnvironment.h/.cpp` | `Editor/` | Viewport floor, lighting, and environment. |
| 201 | `MotionMatchingViewportOverlay.h/.cpp` | `Editor/` | Runtime/editor overlays. |
| 202 | `MotionMatchingViewportDebug.h/.cpp` | `Editor/` | Draws trajectories, contacts, candidates, and targets. |
| 203 | `MotionQueryEditor.h/.cpp` | `Editor/` | Authoring UI for motion queries. |
| 204 | `MotionDatabaseEditor.h/.cpp` | `Editor/` | Database inspection and rebuild UI. |
| 205 | `AnimationLibraryEditor.h/.cpp` | `Editor/` | Animation library browser. |
| 206 | `ChooserEditor.h/.cpp` | `Editor/` | Chooser rule/profile editor. |
| 207 | `WarpingEditor.h/.cpp` | `Editor/` | Warping windows and modifier editor. |
| 208 | `TraversalEditor.h/.cpp` | `Editor/` | Traversal probe/candidate editor. |
| 209 | `SmartObjectEditor.h/.cpp` | `Editor/` | Smart object slot/interaction editor. |
| 210 | `GameplayInteractionEditor.h/.cpp` | `Editor/` | Interaction authoring and debugging. |
| 211 | `CurveRemappingEditor.h/.cpp` | `Editor/` | Curve remapping editor. |
| 212 | `DrawDebugLibrary.h/.cpp` | `Debug/` | Shared debug drawing API for lines, spheres, capsules, arrows, and text. |
| 213 | `MotionDebugDraw.h/.cpp` | `Debug/` | Motion-matching-specific debug primitives. |
| 214 | `PoseDebugDraw.h/.cpp` | `Debug/` | Pose and bone visualization. |
| 215 | `TrajectoryDebugDrawSystem.h/.cpp` | `Debug/` | Trajectory visualization coordinator. |
| 216 | `ContactDebugDraw.h/.cpp` | `Debug/` | Contact points and phases. |
| 217 | `WarpDebugDraw.h/.cpp` | `Debug/` | Warp target and correction visualization. |
| 218 | `InteractionDebugDraw.h/.cpp` | `Debug/` | Interaction alignment and slot visualization. |
| 219 | `TraversalDebugDrawSystem.h/.cpp` | `Debug/` | Traversal probe/result visualization. |
| 220 | `ChooserDebugDraw.h/.cpp` | `Debug/` | Candidate and decision visualization. |

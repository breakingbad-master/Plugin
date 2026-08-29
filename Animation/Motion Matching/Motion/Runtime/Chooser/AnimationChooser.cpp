#include "AnimationChooser.h"

#include <algorithm>
#include <cmath>
#include <limits>

namespace motion {

AnimationChooser::AnimationChooser(std::uint64_t cooldown_frames) : cooldown_frames_(cooldown_frames) {}

bool AnimationChooser::compatible(const AnimationClip &clip, const AnimationChooserContext &context) const {
    for (const std::string &required : context.required_tags) {
        if (std::find(clip.tags.begin(), clip.tags.end(), required) == clip.tags.end()) return false;
    }
    if (!context.surface_tag.empty() && std::find(clip.tags.begin(), clip.tags.end(), context.surface_tag) == clip.tags.end()) return false;
    if (clip.samples.empty() || clip.sample_rate <= 0.0f) return false;
    return true;
}

AnimationChoice AnimationChooser::choose(const AnimationLibrary &library,
                                         const AnimationChooserContext &context,
                                         const AnimationClip *fallback) {
    AnimationChoice best;
    float best_score = std::numeric_limits<float>::infinity();
    for (const AnimationClip *clip : library.find_by_tag(context.required_tags.empty() ? "" : context.required_tags.front())) {
        if (!clip || !compatible(*clip, context)) continue;
        if (clip->id == last_clip_id_ && context.frame < last_frame_ + cooldown_frames_) continue;
        const float clip_speed = clip->samples.front().features.empty() ? 0.0f : clip->samples.front().features.front();
        const float score = std::abs(clip_speed - context.speed) + static_cast<float>(clip->samples.size()) * 0.0001f;
        if (score < best_score || (score == best_score && clip->id < (best.clip ? best.clip->id : "~"))) {
            best_score = score;
            best.clip = clip;
            best.score = score;
            best.fallback = false;
        }
    }
    if (!best.clip) {
        best.clip = fallback;
        best.fallback = true;
        best.score = std::numeric_limits<float>::infinity();
    }
    if (best.clip && !best.fallback) {
        last_clip_id_ = best.clip->id;
        last_frame_ = context.frame;
    }
    return best;
}

void AnimationChooser::reset() {
    last_clip_id_.clear();
    last_frame_ = 0;
}

const std::string &AnimationChooser::last_clip_id() const { return last_clip_id_; }

const ModuleDescriptor &module_animationchooser() {
    static const ModuleDescriptor descriptor{
        "AnimationChooser", "Tag-aware variant chooser with speed scoring, cooldown, history, and safe fallback."};
    return descriptor;
}

} // namespace motion

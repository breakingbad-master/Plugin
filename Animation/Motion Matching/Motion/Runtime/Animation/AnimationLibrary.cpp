#include "AnimationLibrary.h"

#include <algorithm>
#include <utility>

namespace motion {

std::size_t AnimationLibrary::add_clip(AnimationClip clip) {
    const auto existing = std::find_if(clips_.begin(), clips_.end(), [&](const AnimationClip &item) { return item.id == clip.id; });
    if (existing != clips_.end()) {
        *existing = std::move(clip);
        return static_cast<std::size_t>(std::distance(clips_.begin(), existing));
    }
    clips_.push_back(std::move(clip));
    return clips_.size() - 1;
}

const AnimationClip *AnimationLibrary::find(std::string_view id) const {
    const auto it = std::find_if(clips_.begin(), clips_.end(), [id](const AnimationClip &clip) { return clip.id == id; });
    return it == clips_.end() ? nullptr : &*it;
}

std::vector<const AnimationClip *> AnimationLibrary::find_by_tag(std::string_view tag) const {
    std::vector<const AnimationClip *> result;
    for (const AnimationClip &clip : clips_) {
        if (std::find(clip.tags.begin(), clip.tags.end(), tag) != clip.tags.end()) result.push_back(&clip);
    }
    return result;
}

std::size_t AnimationLibrary::clip_count() const { return clips_.size(); }
void AnimationLibrary::clear() { clips_.clear(); }

const ModuleDescriptor &module_animationlibrary() {
    static const ModuleDescriptor descriptor{
        "AnimationLibrary", "Data-driven clip registry with tag lookup, variants, and sampled frames."};
    return descriptor;
}

} // namespace motion

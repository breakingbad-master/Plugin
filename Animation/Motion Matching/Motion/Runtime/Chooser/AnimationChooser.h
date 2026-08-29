#pragma once

#include "../Animation/AnimationLibrary.h"
#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <cstdint>
#include <string>
#include <vector>

namespace motion {

struct AnimationChooserContext {
    std::vector<std::string> required_tags;
    std::string surface_tag;
    float speed = 0.0f;
    std::uint64_t frame = 0;
};

struct AnimationChoice {
    const AnimationClip *clip = nullptr;
    float score = 0.0f;
    bool fallback = true;
};

class AnimationChooser {
public:
    explicit AnimationChooser(std::uint64_t cooldown_frames = 6);
    AnimationChoice choose(const AnimationLibrary &library, const AnimationChooserContext &context,
                           const AnimationClip *fallback);
    void reset();
    const std::string &last_clip_id() const;

private:
    bool compatible(const AnimationClip &clip, const AnimationChooserContext &context) const;
    std::uint64_t cooldown_frames_;
    std::uint64_t last_frame_ = 0;
    std::string last_clip_id_;
};

const ModuleDescriptor &module_animationchooser();

} // namespace motion

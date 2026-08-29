#pragma once

#include "../Core/MMCore.h"
#include "../Core/MMModule.h"

#include <cstddef>
#include <string>
#include <string_view>
#include <vector>

namespace motion {

struct AnimationClip {
    std::string id;
    std::vector<std::string> tags;
    float duration = 0.0f;
    float sample_rate = 30.0f;
    std::vector<MotionCandidate> samples;
};

class AnimationLibrary {
public:
    std::size_t add_clip(AnimationClip clip);
    const AnimationClip *find(std::string_view id) const;
    std::vector<const AnimationClip *> find_by_tag(std::string_view tag) const;
    std::size_t clip_count() const;
    void clear();

private:
    std::vector<AnimationClip> clips_;
};

const ModuleDescriptor &module_animationlibrary();

} // namespace motion

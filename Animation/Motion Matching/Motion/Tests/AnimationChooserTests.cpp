#include "../Runtime/Chooser/AnimationChooser.h"

#include <cassert>
#include <iostream>

using namespace motion;

static AnimationClip clip(const char *id, float speed, const char *tag) {
    AnimationClip result;
    result.id = id;
    result.tags = {"locomotion", tag, "ground"};
    result.duration = 1.0f;
    result.samples.push_back({id, 0, {speed}, result.tags});
    return result;
}

int main() {
    AnimationLibrary library;
    library.add_clip(clip("walk", 2.0f, "walk"));
    library.add_clip(clip("run", 6.0f, "run"));
    AnimationClip fallback = clip("idle", 0.0f, "idle");
    AnimationChooser chooser(10);

    AnimationChooserContext context;
    context.required_tags = {"locomotion", "run"};
    context.speed = 5.5f;
    context.frame = 1;
    AnimationChoice selected = chooser.choose(library, context, &fallback);
    if (!selected.clip || selected.clip->id != "run" || selected.fallback) return 1;

    context.frame = 2;
    AnimationChoice cooled = chooser.choose(library, context, &fallback);
    if (!cooled.clip || cooled.clip->id != "idle" || !cooled.fallback) return 1;

    context.required_tags = {"locomotion", "jump"};
    context.frame = 20;
    AnimationChoice missing = chooser.choose(library, context, &fallback);
    if (!missing.clip || missing.clip->id != "idle" || !missing.fallback) return 1;
    std::cout << "AnimationChooserTests passed\n";
    return 0;
}

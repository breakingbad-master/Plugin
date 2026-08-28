# UVE Animation Godot Plugin

Ito ang unang **Godot 4 GDExtension-compatible adapter** ng UniVex Animation UVE API. Kasama rito ang dalawang UVE asset plugins: `uve.control_rig` para sa 3D control-rig runtime/solver at `uve.motion_query` para sa animation sampling, editor metadata, at diagnostics. Ang orihinal na UVE descriptors at tests ay nasa `thirdparty/uvestudio/Animation/` bilang source contract/reference.

## Godot installation

I-copy ang repository sa isang Godot project, o gamitin ang repository root bilang project workspace. Sa Godot Editor, pumunta sa **Project > Project Settings > Plugins** at i-enable ang **UVE Animation**. Lalabas ang **UVE Plugins** dock sa kanang bahagi. May search bar at checkbox ang bawat plugin. Kapag unchecked ang plugin, hindi ito itinuturing na available sa runtime registry; kapag checked, maaari itong gamitin ng game.

## Android-first viewport and floor support

Ang runtime bridge ay tumatanggap ng `Viewport` at nagse-set ng conservative mobile defaults: 0.75 3D scale, bilinear scaling, 2x MSAA, disabled screen-space AA/TAA, at mas mataas na mesh LOD threshold. Maaaring tawagin ito sa project code:

```gdscript
var uve := UVERuntime.new()
add_child(uve)
uve.configure_android_viewport(get_viewport(), 0.75)
uve.configure_floor($FloorCollision, true, 0.0)
```

Ang floor support ay intentionally generic: puwede itong gamitin sa `CollisionShape3D` upang i-toggle ang collision at taas ng floor, o sa `MeshInstance3D` upang i-toggle ang visible floor mesh. Hindi nito pinapalitan ang physics shape ng game; pinamamahalaan lamang nito ang common floor enable/height behavior.

## Native GDExtension build

Ang `addons/uve_animation/config/uve_animation.gdextension` ay may library slots para Linux, Windows, macOS, Android arm64, Android armeabi-v7a, at Web. Kailangan ng lokal na [godot-cpp](https://github.com/godotengine/godot-cpp) checkout na tugma sa Godot 4.2+ at Android toolchain. Halimbawa:

```bash
scons platform=android arch=arm64 target=template_debug godot_cpp=/path/to/godot-cpp
scons platform=android arch=arm32 target=template_debug godot_cpp=/path/to/godot-cpp
```

Ang compiled `.so` files ay dapat mapunta sa `addons/uve_animation/bin/` ayon sa filenames sa `.gdextension`. Ang GDScript runtime ay nananatiling usable bilang fallback habang ginagawa pa ang native UVE implementation. Ang kasalukuyang C++ bridge ay intentionally maliit at nagbibigay ng native registration plus viewport configuration; ang full UVE solver/database implementation ay susunod na integration stage dahil ang ZIP ay naglalaman ng contracts/tests ngunit walang `Source/Runtime` implementation o compiled library.

## Source mapping

| UVE source | Godot location | Role |
|---|---|---|
| `control_rig/Config/PluginDescriptor.json` | `thirdparty/uvestudio/Animation/control_rig/Config/` | Control Rig identity/capabilities |
| `motion_query/Config/PluginDescriptor.json` | `thirdparty/uvestudio/Animation/motion_query/Config/` | Motion Query identity/capabilities |
| UVE tests | matching `Tests/` folders | Behavioral contract for future native implementation |
| Runtime bridge | `addons/uve_animation/scripts/uve_runtime.gd` | Plugin state, Android viewport, floor support |
| Editor manager | `addons/uve_animation/scripts/uve_plugin.gd` | Searchable check/uncheck dock |
| Native entry point | `native/src/uve_animation.cpp` | Godot GDExtension registration |

## Current limitation

Hindi pa kasama sa ZIP ang actual UVE runtime source (`Source/Runtime`, `Source/Editor`, `Source/Shared`) o prebuilt Android binaries. Kaya ang unang commit na ito ay **compatible integration scaffold at working editor/runtime management layer**, hindi pa ang complete Control Rig/Motion Query solver. Kapag available na ang actual UVE API headers/library, ilalagay ang binding sa `native/src/` at pananatilihin ang parehong plugin IDs at capability contracts.

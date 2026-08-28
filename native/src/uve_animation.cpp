#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

class UVEAnimationNative : public Node {
    GDCLASS(UVEAnimationNative, Node)

protected:
    static void _bind_methods() {}

public:
    void configure_android_viewport(Viewport *viewport, float scale = 0.75f) {
        if (!viewport) return;
        viewport->set_scaling_3d_scale(Math::clamp(scale, 0.5f, 1.0f));
        viewport->set_scaling_3d_mode(Viewport::SCALING_3D_MODE_BILINEAR);
        viewport->set_msaa_3d(Viewport::MSAA_2X);
        viewport->set_screen_space_aa(Viewport::SCREEN_SPACE_AA_DISABLED);
        viewport->set_use_taa(false);
        viewport->set_mesh_lod_threshold(1.5f);
    }
};

void initialize_uve_animation(ModuleInitializationLevel level) {
    if (level != MODULE_INITIALIZATION_LEVEL_SCENE) return;
    ClassDB::register_class<UVEAnimationNative>();
}

void uninitialize_uve_animation(ModuleInitializationLevel level) {
    if (level != MODULE_INITIALIZATION_LEVEL_SCENE) return;
}

extern "C" {
GDExtensionBool GDE_EXPORT uve_animation_library_init(
    GDExtensionInterfaceGetProcAddress get_proc_address,
    GDExtensionClassLibraryPtr library,
    GDExtensionInitialization *initialization) {
    GDExtensionBinding::InitObject init_obj(get_proc_address, library, initialization);
    init_obj.register_initializer(initialize_uve_animation);
    init_obj.register_terminator(uninitialize_uve_animation);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
    return init_obj.init();
}
}

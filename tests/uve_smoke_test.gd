extends Node3D

func _ready() -> void:
    var uve := UVERuntime.new()
    add_child(uve)
    uve.configure_android_viewport(get_viewport(), 0.75)
    var floor := StaticBody3D.new()
    floor.name = "Floor"
    var shape := CollisionShape3D.new()
    var box := BoxShape3D.new()
    box.size = Vector3(20.0, 0.2, 20.0)
    shape.shape = box
    floor.add_child(shape)
    add_child(floor)
    uve.configure_floor(shape, true, 0.0)
    assert(uve.is_plugin_enabled("uve.control_rig"))
    uve.set_plugin_enabled("uve.control_rig", false)
    assert(not uve.is_plugin_enabled("uve.control_rig"))
    uve.set_plugin_enabled("uve.control_rig", true)
    print("UVE smoke test passed")

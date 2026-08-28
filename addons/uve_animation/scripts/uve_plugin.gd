@tool
extends EditorPlugin

const Runtime := preload("res://addons/uve_animation/scripts/uve_runtime.gd")
var runtime: UVERuntime
var panel: VBoxContainer
var search_box: LineEdit
var list_box: VBoxContainer
var status: Label

func _enter_tree() -> void:
    runtime = Runtime.new()
    add_child(runtime)
    panel = VBoxContainer.new()
    panel.name = "UVE Plugins"
    panel.custom_minimum_size = Vector2(280, 0)
    var title := Label.new()
    title.text = "UVE Plugins"
    title.add_theme_font_size_override("font_size", 18)
    panel.add_child(title)
    search_box = LineEdit.new()
    search_box.placeholder_text = "Search plugins..."
    search_box.clear_button_enabled = true
    search_box.text_changed.connect(_refresh)
    panel.add_child(search_box)
    list_box = VBoxContainer.new()
    panel.add_child(list_box)
    status = Label.new()
    status.modulate = Color(0.65, 0.65, 0.65)
    panel.add_child(status)
    add_control_to_dock(DOCK_SLOT_RIGHT_UL, panel)
    _refresh("")

func _exit_tree() -> void:
    if panel:
        remove_control_from_docks(panel)
        panel.queue_free()
    if runtime:
        runtime.queue_free()

func _refresh(query: String) -> void:
    if not list_box:
        return
    for child in list_box.get_children():
        child.queue_free()
    var plugins := runtime.list_plugins(query)
    for item in plugins:
        var row := HBoxContainer.new()
        var check := CheckBox.new()
        check.text = item.name
        check.tooltip_text = "%s\n%s" % [item.id, ", ".join(item.capabilities)]
        check.button_pressed = item.enabled
        check.toggled.connect(func(value: bool): runtime.set_plugin_enabled(item.id, value))
        row.add_child(check)
        var category := Label.new()
        category.text = "  [" + item.category + "]"
        category.modulate = Color(0.55, 0.55, 0.55)
        row.add_child(category)
        list_box.add_child(row)
    status.text = "%d plugin(s) shown. Unchecked plugins are unavailable at runtime." % plugins.size()

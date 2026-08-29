@tool
extends EditorPlugin

const REGISTRY_PATH := "res://Plugin/data/plugins.json"
var window: Window
var search_box: LineEdit
var list_box: VBoxContainer
var status_label: Label
var entries: Array = []
var enabled_state: Dictionary = {}

func _enter_tree() -> void:
    _load_registry()
    var menu := MenuButton.new()
    menu.text = "Plugins"
    menu.get_popup().add_item("Plugin Manager", 1)
    menu.get_popup().id_pressed.connect(_on_menu_pressed)
    add_control_to_container(CONTAINER_TOOLBAR, menu)

func _exit_tree() -> void:
    if window:
        window.queue_free()

func _on_menu_pressed(id: int) -> void:
    if id == 1:
        _open_manager()

func _load_registry() -> void:
    var file := FileAccess.open(REGISTRY_PATH, FileAccess.READ)
    if not file:
        return
    var parsed = JSON.parse_string(file.get_as_text())
    if typeof(parsed) != TYPE_DICTIONARY:
        return
    entries = parsed.get("plugins", [])
    for item in entries:
        enabled_state[item.id] = item.get("enabled", true)

func _save_registry() -> void:
    var output := {"version": 1, "shared_library": "res://Plugin/config/shared_plugins.gdextension", "plugins": []}
    for item in entries:
        var copy: Dictionary = item.duplicate(true)
        copy["enabled"] = enabled_state.get(item.id, true)
        output.plugins.append(copy)
    var file := FileAccess.open(REGISTRY_PATH, FileAccess.WRITE)
    if file:
        file.store_string(JSON.stringify(output, "  "))

func _open_manager() -> void:
    if window:
        window.popup_centered()
        _refresh(search_box.text)
        return
    window = Window.new()
    window.title = "Plugin Manager"
    window.size = Vector2i(520, 620)
    window.min_size = Vector2i(360, 420)
    window.close_requested.connect(func(): window.hide())
    var root := VBoxContainer.new()
    root.set_anchors_and_offsets_preset(Control.PRESET_FULL_RECT)
    root.add_theme_constant_override("separation", 10)
    window.add_child(root)
    var title := Label.new()
    title.text = "Plugins"
    title.add_theme_font_size_override("font_size", 22)
    root.add_child(title)
    var subtitle := Label.new()
    subtitle.text = "One shared GDExtension library • checked plugins are available in game"
    subtitle.modulate = Color(0.65, 0.65, 0.65)
    root.add_child(subtitle)
    search_box = LineEdit.new()
    search_box.placeholder_text = "Search plugins..."
    search_box.clear_button_enabled = true
    search_box.text_changed.connect(_refresh)
    root.add_child(search_box)
    var scroll := ScrollContainer.new()
    scroll.size_flags_vertical = Control.SIZE_EXPAND_FILL
    list_box = VBoxContainer.new()
    list_box.size_flags_horizontal = Control.SIZE_EXPAND_FILL
    scroll.add_child(list_box)
    root.add_child(scroll)
    status_label = Label.new()
    root.add_child(status_label)
    add_child(window)
    _refresh("")
    window.popup_centered()

func _refresh(query: String) -> void:
    if not list_box:
        return
    for child in list_box.get_children():
        child.queue_free()
    var needle := query.strip_edges().to_lower()
    var shown := 0
    for item in entries:
        var plugin_name: String = item.get("name", item.get("id", ""))
        var plugin_id: String = item.get("id", "")
        if not needle.is_empty() and not plugin_name.to_lower().contains(needle) and not plugin_id.to_lower().contains(needle):
            continue
        var row := HBoxContainer.new()
        var check := CheckBox.new()
        check.text = plugin_name
        check.button_pressed = enabled_state.get(plugin_id, true)
        check.tooltip_text = "%s\n%s" % [plugin_id, ", ".join(item.get("capabilities", []))]
        check.toggled.connect(func(value: bool):
            enabled_state[plugin_id] = value
            _save_registry()
        )
        row.add_child(check)
        var category := Label.new()
        category.text = "  [" + str(item.get("category", "Plugin")) + "]"
        category.modulate = Color(0.6, 0.6, 0.6)
        row.add_child(category)
        list_box.add_child(row)
        shown += 1
    status_label.text = "%d plugin(s) shown • %d enabled • shared .so" % [shown, enabled_state.values().count(true)]

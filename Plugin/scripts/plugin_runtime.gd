class_name PluginRuntime
extends Node

const REGISTRY_PATH := "res://Plugin/data/plugins.json"
var enabled_plugins: Dictionary = {}
var shared_extension_path := "res://Plugin/config/shared_plugins.gdextension"

func _ready() -> void:
    reload_plugins()

func reload_plugins() -> void:
    enabled_plugins.clear()
    var file := FileAccess.open(REGISTRY_PATH, FileAccess.READ)
    if not file:
        push_warning("Plugin registry not found: " + REGISTRY_PATH)
        return
    var data = JSON.parse_string(file.get_as_text())
    if typeof(data) != TYPE_DICTIONARY:
        push_error("Invalid plugin registry")
        return
    shared_extension_path = data.get("shared_library", shared_extension_path)
    for plugin in data.get("plugins", []):
        enabled_plugins[plugin.get("id", "")] = plugin.get("enabled", false)

func is_enabled(plugin_id: String) -> bool:
    return enabled_plugins.get(plugin_id, false)

func require_plugin(plugin_id: String) -> bool:
    if is_enabled(plugin_id):
        return true
    push_warning("Plugin is disabled: " + plugin_id)
    return false

func enabled_plugin_ids() -> Array[String]:
    var result: Array[String] = []
    for plugin_id in enabled_plugins:
        if enabled_plugins[plugin_id]:
            result.append(plugin_id)
    return result

class_name UVERuntime
extends Node

## Runtime bridge for the UVE animation API. Native GDExtension can replace this node transparently.
signal plugin_state_changed(plugin_id: String, enabled: bool)

const DEFAULT_VIEWPORT_SCALE := 0.75
const MIN_VIEWPORT_SCALE := 0.5
const MAX_VIEWPORT_SCALE := 1.0

var _plugins: Dictionary = {
    "uve.control_rig": {"name": "UniVex Control Rig", "category": "3D", "enabled": true, "capabilities": ["control_rig.runtime", "control_rig.solver"]},
    "uve.motion_query": {"name": "UniVex Motion Query", "category": "Animation", "enabled": true, "capabilities": ["motion_query.runtime", "motion_query.asset_sampling", "motion_query.editor", "motion_query.diagnostics"]},
}
var viewport_scale := DEFAULT_VIEWPORT_SCALE
var floor_enabled := true
var floor_height := 0.0

func configure_android_viewport(viewport: Viewport, scale: float = DEFAULT_VIEWPORT_SCALE) -> void:
    viewport_scale = clampf(scale, MIN_VIEWPORT_SCALE, MAX_VIEWPORT_SCALE)
    viewport.scaling_3d_scale = viewport_scale
    viewport.scaling_3d_mode = Viewport.SCALING_3D_MODE_BILINEAR
    viewport.msaa_3d = Viewport.MSAA_2X
    viewport.screen_space_aa = Viewport.SCREEN_SPACE_AA_DISABLED
    viewport.use_taa = false
    viewport.mesh_lod_threshold = 1.5
    viewport.transparent_bg = false

func configure_floor(node: Node3D, enabled: bool = true, height: float = 0.0) -> void:
    floor_enabled = enabled
    floor_height = height
    if node is CollisionShape3D:
        node.position.y = height
        node.disabled = not enabled
    elif node is MeshInstance3D:
        node.position.y = height
        node.visible = enabled

func is_plugin_enabled(plugin_id: String) -> bool:
    return bool(_plugins.get(plugin_id, {}).get("enabled", false))

func set_plugin_enabled(plugin_id: String, enabled: bool) -> void:
    if not _plugins.has(plugin_id):
        return
    _plugins[plugin_id]["enabled"] = enabled
    plugin_state_changed.emit(plugin_id, enabled)

func list_plugins(search: String = "") -> Array[Dictionary]:
    var result: Array[Dictionary] = []
    var needle := search.strip_edges().to_lower()
    for plugin_id in _plugins:
        var item: Dictionary = _plugins[plugin_id].duplicate(true)
        item["id"] = plugin_id
        if needle.is_empty() or item.name.to_lower().contains(needle) or plugin_id.contains(needle):
            result.append(item)
    result.sort_custom(func(a, b): return a.name < b.name)
    return result

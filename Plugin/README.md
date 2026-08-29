# Plugin

Ang `Plugin/` ay hiwalay na plugin area sa tabi ng `Asset/`. Maraming plugin entries ang naka-register sa `data/plugins.json`, ngunit iisang shared GDExtension library lang ang ginagamit ng lahat: `config/shared_plugins.gdextension`. Ang compiled libraries ay ilalagay sa `Plugin/bin/`.

Sa editor, i-load ang `Plugin/plugin.cfg`. Lalabas ang **Plugins** button sa toolbar. Kapag pinindot, magbubukas ang floating **Plugin Manager** window. May search field at checkbox bawat plugin. Ang checked plugin ay may `enabled: true` sa registry at maaaring gamitin ng game. Ang unchecked plugin ay may `enabled: false` at bina-block ng `PluginRuntime.require_plugin()`.

## Layout

| Path | Gamit |
|---|---|
| `Plugin/config/shared_plugins.gdextension` | Isang shared GDExtension manifest para sa lahat ng plugin modules |
| `Plugin/data/plugins.json` | Plugin names, categories, capabilities, at enabled state |
| `Plugin/scripts/plugin_manager.gd` | Floating editor window, search, check/uncheck, persistence |
| `Plugin/scripts/plugin_runtime.gd` | Runtime gate para sa enabled plugins |
| `Plugin/bin/` | Shared platform `.so/.dll/.dylib` outputs |

Ang `.gdextension` configuration ay hindi pa naglalaman ng binary mismo. Kailangang ilagay ang compiled shared library sa `Plugin/bin/` gamit ang filename na tumutugma sa platform entry sa manifest.

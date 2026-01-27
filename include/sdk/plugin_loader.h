#pragma once
#include <string>

namespace sdk {

class PluginLoader {
public:
    // Plugin yükler
    static bool Load(const std::string& path);

    // Plugin'i kaldırır
    static void Unload();

    // Plugin'i hot-reload yapar
    static bool Reload(const std::string& path);
};

} // namespace sdk

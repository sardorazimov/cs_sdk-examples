#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <filesystem>

#include "plugin.h"

namespace sdk
{

struct LoadedPlugin
{
    void* handle;
    IPlugin* instance;
    DestroyPluginFn destroy;
};

class PluginManager
{
public:

    bool LoadPlugin(const std::string& path);

    void LoadPluginsFromFolder(const std::string& folder); // ✅ BUNU EKLE

    void Tick(float deltaTime);

    void UnloadAll();

private:

    std::vector<LoadedPlugin> plugins;

};

}

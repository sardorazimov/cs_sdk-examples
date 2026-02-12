#pragma once

#include <vector>
#include <string>
#include "../include/plugin.h"

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

    void Tick(float deltaTime);
    
    void LoadPluginsFromFolder(const std::string& folder);


    void UnloadAll();

private:

    std::vector<LoadedPlugin> plugins;
};

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

    void UnloadAll();

private:

    std::vector<LoadedPlugin> plugins;
};

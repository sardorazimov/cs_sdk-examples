#include "plugin_manager.h"
#include <dlfcn.h>
#include <iostream>

bool PluginManager::LoadPlugin(const char* path)
{
    void* handle = dlopen(path, RTLD_NOW);

    if (!handle)
    {
        std::cout << "Failed to load plugin\n";
        return false;
    }

    CreatePluginFn create =
        (CreatePluginFn)dlsym(handle, "CreatePlugin");

    IPlugin* plugin = create();

    plugin->OnLoad();

    plugins.push_back(plugin);

    return true;
}

void PluginManager::Tick(float dt)
{
    for (auto p : plugins)
        p->OnTick(dt);
}

#include "sdk/plugin_manager.h"

#include <iostream>

#ifdef __APPLE__
#include <dlfcn.h>
#endif

namespace sdk
{

bool PluginManager::LoadPlugin(const std::string& path)
{
#ifdef __APPLE__

    void* handle = dlopen(path.c_str(), RTLD_NOW);

    if (!handle)
    {
        std::cout << "Failed to load plugin: " << dlerror() << "\n";
        return false;
    }

    auto create =
        (CreatePluginFn)dlsym(handle, "CreatePlugin");

    auto destroy =
        (DestroyPluginFn)dlsym(handle, "DestroyPlugin");

    if (!create)
    {
        std::cout << "CreatePlugin not found\n";
        return false;
    }

    IPlugin* plugin = create();

    if (!plugin)
    {
        std::cout << "Plugin creation failed\n";
        return false;
    }

    plugin->OnLoad();

    LoadedPlugin p;
    p.handle = handle;
    p.instance = plugin;
    p.destroy = destroy;

    plugins.push_back(p);

    std::cout << "Loaded plugin: "
              << plugin->GetName()
              << "\n";

#endif

    return true;
}


void PluginManager::Tick(float deltaTime)
{
    for (auto& p : plugins)
    {
        p.instance->OnTick(deltaTime);
    }
}


void PluginManager::UnloadAll()
{
    for (auto& p : plugins)
    {
        p.instance->OnUnload();

        if (p.destroy)
            p.destroy(p.instance);

#ifdef __APPLE__
        dlclose(p.handle);
#endif
    }

    plugins.clear();
}

}

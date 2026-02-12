#include "sdk/plugin_manager.h"
#include "sdk/lua_engine.h"

#include <chrono>
#include <thread>
#include <iostream>

int main()
{
    sdk::PluginManager pm;
    sdk::LuaEngine lua;

#ifdef __APPLE__
    pm.LoadPluginsFromFolder("./plugins");
#endif

    lua.LoadScript("./plugins/gameplay.lua");

    lua.Call("OnEngineStart");

    std::cout << "Engine started\n";

    while (true)
    {
        pm.Tick(0.016f);

        lua.Call("Update");

        std::this_thread::sleep_for(
            std::chrono::milliseconds(1000));
    }

    return 0;
}

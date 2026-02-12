#include "sdk/plugin_manager.h"

#include <chrono>
#include <thread>
#include <iostream>

int main()
{
    sdk::PluginManager pm;

#ifdef __APPLE__
    pm.LoadPlugin("./example_plugin.dylib");
#elif __linux__
    pm.LoadPlugin("./example_plugin.so");
#elif _WIN32
    pm.LoadPlugin("example_plugin.dll");
#endif

    std::cout << "Engine started\n";

    while (true)
    {
        pm.Tick(0.016f);

        std::this_thread::sleep_for(
            std::chrono::milliseconds(16));
    }

    return 0;
}

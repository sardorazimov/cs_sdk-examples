#include "plugin_manager.h"

#include <chrono>
#include <thread>

int main()
{
    PluginManager pm;

#ifdef _WIN32
    pm.LoadPlugin("test_plugin.dll");
#else
    pm.LoadPlugin("./libtest_plugin.so");
#endif

    while (true)
    {
        pm.Tick(0.016f);

        std::this_thread::sleep_for(
            std::chrono::milliseconds(16));
    }

    pm.UnloadAll();

    return 0;
}

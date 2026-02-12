#include "../../include/plugin.h"

#include <iostream>

class TestPlugin : public IPlugin
{
public:

    const char* GetName() override
    {
        return "TestPlugin";
    }

    bool OnLoad() override
    {
        std::cout << "TestPlugin loaded\n";
        return true;
    }

    void OnUnload() override
    {
        std::cout << "TestPlugin unloaded\n";
    }

    void OnTick(float dt) override
    {
        std::cout << "Tick: " << dt << "\n";
    }
};


extern "C"
IPlugin* CreatePlugin()
{
    return new TestPlugin();
}

extern "C"
void DestroyPlugin(IPlugin* plugin)
{
    delete plugin;
}

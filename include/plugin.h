#pragma once

class IPlugin
{
public:
    virtual ~IPlugin() {}

    virtual const char* GetName() = 0;

    virtual bool OnLoad() = 0;

    virtual void OnUnload() = 0;

    virtual void OnTick(float deltaTime) = 0;
};

extern "C"
{
    typedef IPlugin* (*CreatePluginFn)();
    typedef void (*DestroyPluginFn)(IPlugin*);
}

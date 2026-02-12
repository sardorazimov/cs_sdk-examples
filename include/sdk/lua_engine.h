#pragma once

#include <string>

struct lua_State;

namespace sdk
{

class LuaEngine
{
public:

    LuaEngine();

    ~LuaEngine();

    bool LoadScript(const std::string& path);

    void Call(const std::string& function);

private:

    lua_State* L;
};

}

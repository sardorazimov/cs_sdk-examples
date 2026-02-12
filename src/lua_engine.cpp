#include "sdk/lua_engine.h"

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

}



#include <iostream>

namespace sdk
{

LuaEngine::LuaEngine()
{
    L = luaL_newstate();
    luaL_openlibs(L);
}

LuaEngine::~LuaEngine()
{
    lua_close(L);
}

bool LuaEngine::LoadScript(const std::string& path)
{
    if (luaL_dofile(L, path.c_str()) != LUA_OK)
    {
        std::cout << "Lua error: "
                  << lua_tostring(L, -1)
                  << "\n";

        return false;
    }

    std::cout << "Loaded Lua script: "
              << path << "\n";

    return true;
}

void LuaEngine::Call(const std::string& function)
{
    lua_getglobal(L, function.c_str());

    if (lua_isfunction(L, -1))
    {
        lua_pcall(L, 0, 0, 0);
    }
}

}

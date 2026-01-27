#include "sdk/scripting/lua_api.h"
#include "sdk/ecs/ecs.h"
#include "sdk/ecs/components.h"

#include <lua.hpp>
#include <iostream>

using namespace sdk::ecs;

namespace sdk::scripting {

static lua_State* g_Lua = nullptr;

// -----------------------------
// C -> Lua bindings
// -----------------------------

static int lua_CreateEntity(lua_State* L) {
    EntityID id = ECS::CreateEntity();
    lua_pushinteger(L, static_cast<lua_Integer>(id));
    return 1;
}

static int lua_SetPosition(lua_State* L) {
    EntityID id = (EntityID)lua_tointeger(L, 1);
    float x = (float)lua_tonumber(L, 2);
    float y = (float)lua_tonumber(L, 3);
    float z = (float)lua_tonumber(L, 4);

    if (!ECS::IsValid(id))
        return 0;

    if (!ECS::HasComponent<Position>(id)) {
        ECS::AddComponent<Position>(id, {});
    }

    auto* pos = ECS::GetComponent<Position>(id);
    pos->x = x;
    pos->y = y;
    pos->z = z;

    return 0;
}

static int lua_Damage(lua_State* L) {
    EntityID id = (EntityID)lua_tointeger(L, 1);
    int dmg = (int)lua_tointeger(L, 2);

    if (!ECS::IsValid(id))
        return 0;

    if (!ECS::HasComponent<Health>(id)) {
        ECS::AddComponent<Health>(id, {});
    }

    auto* hp = ECS::GetComponent<Health>(id);
    hp->value -= dmg;

    return 0;
}

// -----------------------------
// Public API
// -----------------------------

bool InitLua() {
    g_Lua = luaL_newstate();
    luaL_openlibs(g_Lua);

    RegisterEntityAPI(g_Lua);

    return true;
}

void ShutdownLua() {
    if (g_Lua) {
        lua_close(g_Lua);
        g_Lua = nullptr;
    }
}

bool RunScript(const char* filePath) {
    if (!g_Lua)
        return false;

    if (luaL_dofile(g_Lua, filePath) != LUA_OK) {
        std::cout << "[Lua ERROR] "
                  << lua_tostring(g_Lua, -1) << std::endl;
        return false;
    }
    return true;
}

void RegisterEntityAPI(lua_State* L) {
    lua_register(L, "CreateEntity", lua_CreateEntity);
    lua_register(L, "SetPosition", lua_SetPosition);
    lua_register(L, "Damage", lua_Damage);
}

} // namespace sdk::scripting

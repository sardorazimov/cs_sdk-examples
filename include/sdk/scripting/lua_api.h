#pragma once
#include <cstdint>
#include "../ecs/entity.h"

struct lua_State;

namespace sdk::scripting {

// Lua VM başlat / kapat
void InitLua();
void ShutdownLua();

// Script çalıştır
bool RunScript(const char* path);

// ECS → Lua API
void RegisterEntityAPI(lua_State* L);

} // namespace sdk::scripting

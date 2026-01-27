#pragma once
#include <cstdint>

// Forward declaration (Lua header'ı burada include etmiyoruz)
struct lua_State;

namespace sdk::scripting {

    // ----------------------------------
    // Lua VM yaşam döngüsü
    // ----------------------------------

    // Lua VM başlatır
    bool InitLua();

    // Lua VM kapatır
    void ShutdownLua();

    // Lua script çalıştırır
    bool RunScript(const char* filePath);

    // ----------------------------------
    // SDK -> Lua API kayıtları
    // ----------------------------------

    // Entity / ECS API'lerini Lua'ya açar
    void RegisterEntityAPI(lua_State* L);

} // namespace sdk::scripting

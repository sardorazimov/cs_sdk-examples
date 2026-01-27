#pragma once

namespace sdk {

class SDK {
public:
    // SDK'yi başlatır (engine bağlanır, sistemler ayağa kalkar)
    static bool Init();

    // SDK'yi temiz kapatır
    static void Shutdown();
};

} // namespace sdk

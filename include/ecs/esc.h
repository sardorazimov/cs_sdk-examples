#include <vector>

namespace sdk::ecs {

class ECS {
public:
    // mevcut fonksiyonlar...

    // Tüm aktif entity'leri döndürür
    static std::vector<EntityID> GetAllEntities();
};

}

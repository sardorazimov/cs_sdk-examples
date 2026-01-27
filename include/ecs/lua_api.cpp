#include <vector>

namespace sdk::ecs {

std::vector<EntityID> ECS::GetAllEntities() {
    std::vector<EntityID> result;
    for (EntityID id : g_AliveEntities) {
        result.push_back(id);
    }
    return result;
}

}

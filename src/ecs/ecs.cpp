#include "sdk/ecs/ecs.h"
#include <unordered_map>
#include <typeindex>

namespace sdk::ecs {

static EntityID nextEntity = 1;
static std::unordered_map<EntityID, bool> alive;

EntityID ECS::CreateEntity() {
    EntityID id = nextEntity++;
    alive[id] = true;
    return id;
}

void ECS::DestroyEntity(EntityID entity) {
    alive.erase(entity);
}

bool ECS::IsValid(EntityID entity) {
    return alive.count(entity) != 0;
}

} // namespace sdk::ecs

#include "sdk/ecs/ecs.h"
#include "sdk/ecs/components.h"

#include <unordered_map>
#include <unordered_set>
#include <typeindex>
#include <memory>

namespace sdk::ecs {

    // -----------------------------
    // Entity management
    // -----------------------------

    static EntityID g_NextEntityID = 1;
    static std::unordered_set<EntityID> g_AliveEntities;

    EntityID ECS::CreateEntity() {
        EntityID id = g_NextEntityID++;
        g_AliveEntities.insert(id);
        return id;
    }

    void ECS::DestroyEntity(EntityID entity) {
        g_AliveEntities.erase(entity);
    }

    bool ECS::IsValid(EntityID entity) {
        return g_AliveEntities.count(entity) != 0;
    }

    // -----------------------------
    // Component storage (generic)
    // -----------------------------

    // type_index -> (entity -> component)
    static std::unordered_map<
        std::type_index,
        std::unordered_map<EntityID, std::shared_ptr<void>>
    > g_ComponentStorage;

    template<typename T>
    static std::unordered_map<EntityID, std::shared_ptr<void>>& GetStorage() {
        return g_ComponentStorage[std::type_index(typeid(T))];
    }

    // -----------------------------
    // Component API
    // -----------------------------

    template<typename T>
    bool ECS::HasComponent(EntityID entity) {
        auto& storage = GetStorage<T>();
        return storage.count(entity) != 0;
    }

    template<typename T>
    T* ECS::GetComponent(EntityID entity) {
        auto& storage = GetStorage<T>();
        if (storage.count(entity) == 0)
            return nullptr;

        return static_cast<T*>(storage[entity].get());
    }

    template<typename T>
    void ECS::AddComponent(EntityID entity, const T& component) {
        auto& storage = GetStorage<T>();
        storage[entity] = std::make_shared<T>(component);
    }

    template<typename T>
    void ECS::RemoveComponent(EntityID entity) {
        auto& storage = GetStorage<T>();
        storage.erase(entity);
    }

} // namespace sdk::ecs

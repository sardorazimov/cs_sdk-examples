#pragma once
#include "entity.h"

namespace sdk::ecs {

class ECS {
public:
    // ---------------------------
    // Entity yönetimi
    // ---------------------------

    // Yeni entity oluşturur
    static EntityID CreateEntity();

    // Entity siler
    static void DestroyEntity(EntityID entity);

    // Entity geçerli mi?
    static bool IsValid(EntityID entity);

    // ---------------------------
    // Component yönetimi
    // ---------------------------

    template<typename T>
    static bool HasComponent(EntityID entity);

    template<typename T>
    static T* GetComponent(EntityID entity);

    template<typename T>
    static void AddComponent(EntityID entity, const T& component);

    template<typename T>
    static void RemoveComponent(EntityID entity);
};

} // namespace sdk::ecs

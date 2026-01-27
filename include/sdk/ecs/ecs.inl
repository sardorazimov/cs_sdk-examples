#pragma once
#include <typeindex>

namespace sdk::ecs {

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

}

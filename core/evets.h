#pragma once
#include <functional>
#include <string>

using EventCallback = std::function<void()>;

class EventManager {
public:
    static void Register(const std::string& name, EventCallback cb);
    static void Trigger(const std::string& name);
};

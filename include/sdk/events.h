#pragma once

#include <functional>
#include <vector>
#include <unordered_map>
#include <any>

namespace sdk
{

enum class EventType
{
    EngineStart,
    Update,
    Shutdown,
    PluginLoaded,
    Custom
};

struct Event
{
    EventType type;

    std::any data;
};

using EventCallback = std::function<void(const Event&)>;

class EventManager
{
public:

    void Subscribe(EventType type, EventCallback callback)
    {
        listeners[type].push_back(callback);
    }

    void Emit(const Event& event)
    {
        auto it = listeners.find(event.type);

        if (it == listeners.end())
            return;

        for (auto& cb : it->second)
        {
            cb(event);
        }
    }

private:

    std::unordered_map<EventType,
        std::vector<EventCallback>> listeners;
};

}

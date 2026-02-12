#pragma once

#include <functional>
#include <vector>

enum class EventType
{
    None = 0,
    Update,
    Render,
    KeyPress,
    PluginLoaded,
    PluginUnloaded
};

class Event
{
public:
    EventType type;

    Event(EventType t) : type(t) {}
};

using EventCallback = std::function<void(const Event&)>;

class EventManager
{
public:
    void Subscribe(EventCallback cb)
    {
        callbacks.push_back(cb);
    }

    void Emit(const Event& event)
    {
        for (auto& cb : callbacks)
        {
            cb(event);
        }
    }

private:
    std::vector<EventCallback> callbacks;
};

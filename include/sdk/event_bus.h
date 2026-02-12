#pragma once

#include <unordered_map>
#include <vector>
#include <functional>
#include <typeindex>

namespace sdk
{

class EventBus
{
public:

    template<typename EventType>
    static void Subscribe(std::function<void(const EventType&)> callback)
    {
        auto& handlers = GetHandlers<EventType>();
        handlers.push_back(callback);
    }

    template<typename EventType>
    static void Emit(const EventType& event)
    {
        auto& handlers = GetHandlers<EventType>();

        for (auto& handler : handlers)
        {
            handler(event);
        }
    }

private:

    template<typename EventType>
    static std::vector<std::function<void(const EventType&)>>& GetHandlers()
    {
        static std::vector<std::function<void(const EventType&)>> handlers;
        return handlers;
    }
};

}

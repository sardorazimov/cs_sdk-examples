#pragma once

#include "events.h"

namespace sdk
{

class Engine
{
public:

    static EventManager& GetEventManager()
    {
        static EventManager instance;
        return instance;
    }

};

}

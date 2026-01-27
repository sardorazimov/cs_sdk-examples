#pragma once
#include <functional>

namespace sdk {

using TickCallback = std::function<void()>;

class Tick {
public:
    // Her frame çağrılacak callback ekler
    static void Register(TickCallback callback);

    // Engine loop tarafından çağrılır
    static void Update();
};

} // namespace sdk

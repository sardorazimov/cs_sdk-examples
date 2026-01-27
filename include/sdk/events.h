#pragma once
#include <functional>
#include <string>

namespace sdk {

using EventCallback = std::function<void()>;

class Events {
public:
    // Event'e listener ekler
    static void On(const std::string& name, EventCallback callback);

    // Event tetikler
    static void Emit(const std::string& name);
};

} // namespace sdk

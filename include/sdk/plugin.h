#pragma once

namespace sdk {

class IPlugin {
public:
    virtual ~IPlugin() = default;

    // Plugin yüklendiğinde çağrılır
    virtual void OnLoad() = 0;

    // Plugin kaldırılırken çağrılır
    virtual void OnUnload() = 0;
};

} // namespace sdk

#pragma once

namespace sdk {

class IEngine {
public:
    virtual ~IEngine() = default;

    // Engine log / console output
    virtual void Print(const char* message) = 0;

    // Engine tick sayısı (frame counter)
    virtual int GetTick() const = 0;
};

} // namespace sdk

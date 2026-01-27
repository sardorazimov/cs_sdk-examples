#pragma once

class IEngine {
public:
    virtual void Print(const char* msg) = 0;
    virtual int GetLocalPlayer() = 0;
};

#pragma once

class Entity {
public:
    virtual int GetHealth() = 0;
    virtual bool IsAlive() = 0;
    virtual int GetTeam() = 0;
};

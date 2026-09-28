#pragma once
#include "Vec2.hpp"

class Entity {
protected:
    Vec2 position {0.0, 0.0};
    Vec2 prevPosition {0.0, 0.0};
    Vec2 speed {0.0, 0.0};
    Vec2 acceleration {0.0, 0.0};
    Vec2 size {0.0, 0.0};
    double maxSpeed;
    bool active {true};
    
public:
    Entity() = default;
    Entity(Vec2 pos, Vec2 spd, Vec2 acc, Vec2 size, double maxSpd);
    virtual ~Entity() = default;
    void update(double dt);
    Vec2 getPosition() const { return position; }
    Vec2 getPrevPosition() const { return prevPosition; }
    Vec2 getSpeed() const { return speed; }
    Vec2 getSize() const { return size; }
    bool isActive() const { return active; }
    void deactivated() { active = false; }
};

bool checkCollision(const Entity& a, const Entity& b);
#pragma once
#include "Entity.hpp"
#include "Constants.hpp"

using namespace Constants;

class Bullet : public Entity {
public:
    Bullet() = default;
    Bullet(Vec2 pos, Vec2 spd, Vec2 acc)
        : Entity(pos, spd, acc, INTERCEPTOR_SIZE, INTERCEPTOR_VMAX) {}
};
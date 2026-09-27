#pragma once
#include "Vec2.hpp"
#include "Entity.hpp"

class Threat : public Entity {
public:
    Threat() = default;
    Threat(Vec2 pos, Vec2 spd, Vec2 acc, Vec2 siz)
        : Entity(pos, spd, acc, siz, 400.0) {}
};
#include "Entity.hpp"
#include "Vec2.hpp"
#include "Constants.hpp"
#include <iostream>

using namespace Constants;

Entity::Entity(Vec2 pos, Vec2 spd, Vec2 acc, Vec2 siz, double maxSpd)
    : position(pos), speed(spd), acceleration(acc), size(siz), maxSpeed(maxSpd) {
}

void Entity::update(double dt) {
    position += speed * dt;
    if (position.x < X_MIN || position.x > X_MAX || position.y < Y_MIN || position.y > Y_MAX) {
        active = false;
    }
    if (speed.module() < maxSpeed) {
        speed += acceleration * dt;
    }
}

bool checkCollision(const Entity& a, const Entity& b) {
    double totalRadius = PROXIMITY_RADIUS;
    Vec2 diff = a.getPosition() - b.getPosition();
    return diff.moduleSquared() <= (totalRadius * totalRadius);
}
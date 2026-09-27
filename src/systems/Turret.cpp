#include "Turret.hpp"
#include <cmath>
#include "Constants.hpp"

void Turret::setAngle(double angle) {
    if (std::abs(desiredAngle - angle) > 0.5) {
        lockOn = false;
    }
    desiredAngle = angle;
}

void Turret::update(double dt) {
    timeSinceLastShot += dt;
    double diff = desiredAngle - currentAngle;
    if (std::abs(diff) < 0.2) {
        lockOn = true;
    } else {
        if (std::abs(diff) <= maxTurnRate * dt) {
            currentAngle = desiredAngle;
            lockOn = true;
        } else if (diff > 0) {
            currentAngle += maxTurnRate * dt;
        } else {
            currentAngle -= maxTurnRate * dt;
        }
    }
}

Bullet Turret::fire() {
    timeSinceLastShot = 0.0;
    return Bullet(position, Vec2::fromPolar(currentAngle, Constants::INTERCEPTOR_VMAX), Vec2{0.0, 0.0});
}
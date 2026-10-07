#pragma once
#include "Vec2.hpp"
#include "Bullet.hpp"
#include "Constants.hpp"

class Turret {
    Vec2 position {10000.0, 5000.0};
    double currentAngle {0.0};
    double desiredAngle {0.0};
    double maxTurnRate {60.0};
    bool lockOn {false};
    double fireRate {Constants::FIRE_RATE};
    double timeSinceLastShot {0.0};
    bool fireEnabled {false};

public:
    Turret() = default;
    void setAngle(double angle);
    void update(double dt);
    bool canFire(double distance) const {
        return lockOn && (timeSinceLastShot >= (1.0 / fireRate) && distance<Constants::MAX_ENGAGEMENT_RANGE);
    }
    Bullet fire();
    Vec2 getPosition() const { return position; }
    double getCurrentAngle() const { return currentAngle; }
};
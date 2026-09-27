#pragma once
#include "Vec2.hpp"
#include "Bullet.hpp"

class Turret {
    Vec2 position {10000.0, 5000.0};
    double currentAngle {0.0};
    double desiredAngle {0.0};
    double maxTurnRate {60.0};
    bool lockOn {false};
    double fireRate {1.0};
    double timeSinceLastShot {0.0};
    bool fireEnabled {false};

public:
    Turret() = default;
    void setAngle(double angle);
    void update(double dt);
    bool canFire() const {
        return lockOn && (timeSinceLastShot >= (1.0 / fireRate));
    }
    Bullet fire();
    Vec2 getPosition() const { return position; }
    double getCurrentAngle() const { return currentAngle; }
};
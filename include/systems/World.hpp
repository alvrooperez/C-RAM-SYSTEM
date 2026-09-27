#pragma once
#include "Radar.hpp"
#include "Turret.hpp"
#include "Bullet.hpp"
#include "Threat.hpp"
#include <vector>

class World {
    Radar radar;
    Turret turret;
    Threat threat;
    std::vector<Bullet> bullets;
    bool running {true};

public:
    World();
    // Getters
    const Turret& getTurret() const { return turret; }
    const Radar& getRadar() const { return radar; }
    const Threat& getTarget() const { return threat; }
    const std::vector<Bullet>& getBullets() const { return bullets; }

    bool isRunning() const { return running && threat.isActive(); }
    void update (double dt);
    void checkCollisions();


};
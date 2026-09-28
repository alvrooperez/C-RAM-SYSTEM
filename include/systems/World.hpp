#pragma once
#include "Radar.hpp"
#include "Turret.hpp"
#include "Bullet.hpp"
#include "Threat.hpp"
#include <vector>

class World {
    Radar radar;
    Turret turret;
    std::vector<Threat> threats;
    std::vector<Bullet> bullets;
    bool running {true};

public:
    World();
    // Getters
    const Turret& getTurret() const { return turret; }
    const Radar& getRadar() const { return radar; }
    const std::vector<Threat>& getThreats() const { return threats; }
    const std::vector<Bullet>& getBullets() const { return bullets; }

    bool isRunning() const { return running && !getThreats().empty(); }
    void update (double dt);
    void checkCollisions();
    void fire(RadarPing ping, double dt);
    void cleanup();
    void spawnWave();

};
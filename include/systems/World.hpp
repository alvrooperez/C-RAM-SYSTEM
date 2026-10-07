#pragma once
#include "Radar.hpp"
#include "Turret.hpp"
#include "Bullet.hpp"
#include "Threat.hpp"
#include "FireControl.hpp"
#include <vector>
#include <mutex>
#include "Vec2.hpp"

struct WorldSnapshot {
    Vec2 turretPos;
    double turretAngle {0.0};
    std::vector<Vec2> threatPositions;
    std::vector<Vec2> bulletPositions;
};

class World {
    Radar radar;
    Turret turret;
    FireControl fireControl;
    std::vector<Threat> threats;
    std::vector<Bullet> bullets;
    bool running {true};

    int totalSpawned {0};
    int totalDestroyed {0};
    int baseHits{0};
    //Mutex
    std::mutex worldMutex;

public:
    World();
    // Getters
    const Turret& getTurret() const { return turret; }
    const Radar& getRadar() const { return radar; }
    const std::vector<Threat>& getThreats() const { return threats; }
    const std::vector<Bullet>& getBullets() const { return bullets; }

    bool isRunning() const { return running && !getThreats().empty(); }
    int getTotalSpawned() const {return totalSpawned;};
    int getTotalDestroyed() const {return totalDestroyed;};
    int getHits() const {return baseHits;};

    void update (double dt);
    void checkCollisions();
    void fire(RadarPing ping, double dt);

    void cleanup();
    void spawnWave();

    WorldSnapshot getSnapshot();

};
#include "World.hpp"
#include "Radar.hpp"
#include <iostream>
#include "Constants.hpp"
#include <iomanip>


World::World()
        : threat({0.0, 5000.0}, {100.0, 0.0}, {1.0, 0.0}, {10.0, 20.0}) {
        bullets.reserve(100);
    
}

void World::update(double dt){

    // Moving update
        threat.update(dt);
        for (auto& bullet:bullets){
            bullet.update(dt);
        }
        // radar
        RadarPing ping=radar.scan(threat);
            if (ping.detected){
                turret.setAngle(ping.angleDegrees);
            }
        // turret
        turret.update(dt);
        if (ping.detected &&turret.canFire()){
            bullets.push_back(turret.fire());
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Fire! Bullet angle: ,"<< ping.angleDegrees << std::endl;
        }

        // check Collisions
        this->checkCollisions();
}

void World::checkCollisions(){
    for (auto& bullet:bullets){
            if (bullet.isActive() && checkCollision(bullet, threat)) {
            std::cout << "IMPACT: THREAT DESTROYED" << std::endl;
            bullet.deactivated();
            threat.deactivated();
            running=false;
        }
        }
}
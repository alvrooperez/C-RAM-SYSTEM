#include "World.hpp"
#include "Radar.hpp"
#include <iostream>
#include "Constants.hpp"
#include "FireControl.hpp"
#include "MathUtils.hpp"
#include <iomanip>
#include <vector>




World::World()
        //: threat({0.0, 3000.0}, {100.0, 0.0}, {1.0, 0.0}, {10.0, 20.0}) 
        {
        bullets.reserve(100);
        threats.reserve(20);
        spawnWave();
    
}

void World::update(double dt){

    // Moving update
        for (auto& threat : threats){
            if (threat.isActive()){
            threat.update(dt);
            
            }
        }
        for (auto& bullet:bullets){
            bullet.update(dt);
        }
        // radar
        for (auto& threat : threats){
            if (threat.isActive()){
                RadarPing ping=radar.scan(threat);
                fire(ping,dt);
                break;
            }
        }
        

        
        
        

        // check Collisions
        this->checkCollisions();
        cleanup();
}

void World::checkCollisions(){
    for (auto& threat:threats){
        for (auto& bullet:bullets){
                if (bullet.isActive() && checkCollision(bullet, threat) && threat.isActive()) {
                std::cout << "IMPACT: THREAT DESTROYED" << std::endl;
                bullet.deactivated();
                threat.deactivated();
                totalDestroyed ++;
                //running=false;
                }
        }
    }
}

void World::fire(RadarPing ping,double dt){
    //FireControl
        FireControl fire;
        if (ping.detected){
        FireSolution sol=fire.calculateIntercept(ping,radar.getPosition());
            if (sol.hasSolution){
                turret.setAngle(sol.interceptAngle);
                turret.update(dt);

                if (turret.canFire()){
                    bullets.push_back(turret.fire());
                    std::cout << std::fixed << std::setprecision(2);
                    std::cout << "Fire! Bullet angle: ,"<< sol.interceptAngle << std::endl;
                }

            }else {
                turret.update(dt);
            }
            
        } else {
            turret.update(dt);
        }

}

void World::cleanup() {
        // Elimina físicamente del vector todos los que NO estén activos
        std::erase_if(threats, [](const Threat& t) { return !t.isActive(); });
        std::erase_if(bullets, [](const Bullet& b) { return !b.isActive(); });
}

void World::spawnWave(){
    int count = MathUtils::getRandomInt(Constants::WAVE_MIN_COUNT, Constants::WAVE_MAX_COUNT);

    for (int i = 0; i < count; i++) {
        // Initial Position
        double x = MathUtils::getRandom(Constants::SPAWN_X_MIN, Constants::SPAWN_X_MAX);
        double y = MathUtils::getRandom(Constants::SPAWN_Y_MIN, Constants::SPAWN_Y_MAX);
        Vec2 startPos{ x, y };

        // Target Position
        double targetY = MathUtils::getRandom(Constants::TARGET_Y_MIN, Constants::TARGET_Y_MAX);
        Vec2 targetPos{ Constants::X_MAX, targetY };

        // Speed and direction
        double speed = MathUtils::getRandom(Constants::THREAT_MIN_SPEED, Constants::THREAT_MAX_SPEED);
        Vec2 direction = (targetPos - startPos).normalized();
        Vec2 velocity = direction * speed;

        // threat Creation
        threats.emplace_back(startPos, velocity, Vec2{0.0, 0.0}, Constants::THREAT_SIZE);
    }
    totalSpawned+=count;
    std::cout << "WAVE LAUNCHED WITH : " << count << " THREATS!" << std::endl;
    
}
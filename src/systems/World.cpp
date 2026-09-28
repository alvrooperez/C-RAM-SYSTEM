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
        threats.emplace_back(Vec2{0.0, 5000.0}, Vec2{100.0, 0.0}, Vec2{0.0, 0.0}, Vec2{10.0, 20.0});
        threats.emplace_back(Vec2{0.0, 2000.0}, Vec2{120.0, 40.0}, Vec2{0.0, 0.0}, Vec2{10.0, 20.0});
    
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
    int count=random(5,10)
    
    for (int i=0;i<count;i++){
        x=random (1000, 4000)
        y=random(100,9000)
        y_t=random(3000,7000)

        //calculate speedvector
        speed=random(50,300)
        v= (dt)/|dt|
        vf=speed*v

        threats.emplace_back(
    }
}
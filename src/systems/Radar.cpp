#include "Radar.hpp"
#include "Vec2.hpp"
#include "Entity.hpp"

RadarPing Radar::scan(const Entity &E) const {
    RadarPing detec;
    detec.targetPos = E.getPosition();
    Vec2 relPos = detec.targetPos - position;
    detec.distance = relPos.module();

    if (detec.distance > maxRange) {
        return detec;
    }
    detec.detected = true;
    
    detec.targetVel=E.getSpeed();
    return detec;
}
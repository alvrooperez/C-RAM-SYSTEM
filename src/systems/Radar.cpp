#include "Radar.hpp"
#include "Vec2.hpp"
#include "Entity.hpp"

RadarPing Radar::scan(const Entity &E) const {
    RadarPing detec;
    detec.relPos = E.getPosition() - position;
    detec.distance = detec.relPos.module();

    if (detec.distance > maxRange) {
        return detec;
    }
    detec.detected = true;
    detec.angleDegrees = detec.relPos.angle();
    return detec;
}
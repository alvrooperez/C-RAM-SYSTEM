#include "Radar.hpp"
#include "Vec2.hpp"
#include "Threat.hpp"

std::vector<RadarPing> Radar::scan(const std::vector<Threat> &V) const {
    std::vector<RadarPing> detections;
    detections.reserve(V.size());
    for (const auto &threat:V){
        RadarPing detec;
        
        detec.targetPos = threat.getPosition();
        Vec2 relPos = detec.targetPos - position;
        
        double distSq = relPos.moduleSquared();
        if (distSq > maxRange*maxRange) {
            
            continue;
        }
        detec.distance = relPos.module();
        detec.detected = true;
        
        detec.targetVel=threat.getSpeed();
        detections.push_back(detec);
    }
    return detections;
    
}
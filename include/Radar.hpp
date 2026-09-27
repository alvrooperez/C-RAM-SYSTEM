#pragma once
#include "Vec2.hpp"
#include "Constants.hpp"
#include "Entity.hpp"

struct RadarPing {
    bool detected {false};
    Vec2 relPos {0.0, 0.0}; 
    double distance {0.0};            
    double angleDegrees {0.0};         
};

class Radar {
    Vec2 position {10000.0, 5000.0};
    double maxRange {Constants::RADAR_RANGE};

public:
    Radar() = default;
    RadarPing scan(const Entity &E) const;
};
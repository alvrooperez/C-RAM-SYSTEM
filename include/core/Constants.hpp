#pragma once
#include "Vec2.hpp"

namespace Constants {
    inline constexpr double GRAVITY = 9.81;        // m/s^2
    inline constexpr double RADAR_RANGE = 8000.0; // meters 10k
    
    inline constexpr double DRONE_SPEED = 60.0;    // m/s (~216 km/h)
    inline constexpr double MISSILE_SPEED = 300.0; // m/s (Mach 0.9)
    inline constexpr double THREAT_VMAX = 400.0;   // m/s

    // Missiles/Bullets
    inline constexpr double INTERCEPTOR_VMAX = 700.0; // m/s (~Mach 2)
    inline constexpr double PROXIMITY_RADIUS = 25.0;  
    inline constexpr Vec2 INTERCEPTOR_SIZE {3.0, 0.5};
    inline constexpr double FIRE_RATE = 0.1; 

    // Limits
    inline constexpr double Y_MAX = 10000.0;
    inline constexpr double Y_MIN = 0.0;
    inline constexpr double X_MAX = 10000.0;
    inline constexpr double X_MIN = 0.0;

    //Waves
    inline constexpr double SPAWN_X_MIN = 1000.0;
    inline constexpr double SPAWN_X_MAX = 4000.0;
    inline constexpr double SPAWN_Y_MIN = 1000.0;
    inline constexpr double SPAWN_Y_MAX = 9000.0;
    inline constexpr double TARGET_Y_MIN = 3000.0;
    inline constexpr double TARGET_Y_MAX = 7000.0;
    inline constexpr double THREAT_MIN_SPEED = 60.0;
    inline constexpr double THREAT_MAX_SPEED = 250.0;
}
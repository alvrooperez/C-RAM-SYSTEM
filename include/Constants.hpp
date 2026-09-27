#pragma once
#include "Vec2.hpp"

namespace Constants {
    inline constexpr double GRAVITY = 9.81;        // m/s^2
    inline constexpr double RADAR_RANGE = 10000.0; // meters
    
    inline constexpr double DRONE_SPEED = 60.0;    // m/s (~216 km/h)
    inline constexpr double MISSILE_SPEED = 300.0; // m/s (Mach 0.9)
    inline constexpr double THREAT_VMAX = 400.0;   // m/s

    // Missiles/Bullets
    inline constexpr double INTERCEPTOR_VMAX = 700.0; // m/s (~Mach 2)
    inline constexpr double PROXIMITY_RADIUS = 25.0;  // 25 m radio de fragmentación letal
    inline constexpr Vec2 INTERCEPTOR_SIZE {3.0, 0.5};

    // Limits
    inline constexpr double Y_MAX = 10000.0;
    inline constexpr double Y_MIN = 0.0;
    inline constexpr double X_MAX = 10000.0;
    inline constexpr double X_MIN = 0.0;
}
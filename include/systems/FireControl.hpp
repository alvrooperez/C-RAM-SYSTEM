#pragma once
#include "core/Vec2.hpp"
#include <utility>
#include "Radar.hpp"
#include "Constants.hpp"
#include <optional>

struct FireSolution {
    bool hasSolution {false};
    double interceptAngle {0.0};
    double timeToImpact {0.0};
    double distance {0.0};
    Vec2 interceptPoint {0.0, 0.0};
};

class FireControl {
    double bulletSpeed=Constants::INTERCEPTOR_VMAX;
public:
    FireSolution calculateIntercept(const RadarPing& ping,Vec2 gunPos) const;
    std::optional<RadarPing> selectTarget(const std::vector<RadarPing>& pings, Vec2 basePos) const;
    
};
std::optional<double> sol2equation(double a, double b, double c);
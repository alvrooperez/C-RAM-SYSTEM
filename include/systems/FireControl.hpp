#pragma once
#include "core/Vec2.hpp"

struct FireSolution {
    bool hasSolution {false};
    double interceptAngle {0.0};
    double timeToImpact {0.0};
    Vec2 interceptPoint {0.0, 0.0};
};

class FireControl {
public:
    FireSolution calculateIntercept(Vec2 gunPos, double bulletSpeed, Vec2 targetPos, Vec2 targetVel) const;
};
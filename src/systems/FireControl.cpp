#include "FireControl.hpp"
#include "core/Vec2.hpp"
#include <cmath>
#include <optional>
#include "Radar.hpp"
#include "Constants.hpp"
#include <limits>

FireSolution FireControl::calculateIntercept(const RadarPing& ping,Vec2 gunPos) const{
    
    FireSolution sol;

    Vec2 d = ping.targetPos-gunPos;
    
    double a= ping.targetVel.moduleSquared()-bulletSpeed*bulletSpeed;
    double b= (d*ping.targetVel)*2;
    double c = d.module()*d.module();
    auto tOpt = sol2equation(a, b, c);
    if (tOpt.has_value() ) {
        double t = tOpt.value();
        // We have solution
        sol.hasSolution=true;
        sol.timeToImpact=t;
        sol.interceptPoint=ping.targetPos+ ping.targetVel*t;
        sol.interceptAngle=(sol.interceptPoint - gunPos).angle();
        sol.distance=d.module();
    }

    return sol;
}

std::optional<RadarPing> FireControl::selectTarget(const std::vector<RadarPing>& pings, Vec2 basePos) const {

    std::optional<RadarPing> bestTarget = std::nullopt;
    double minTtc = std::numeric_limits<double>::infinity();
    for (const auto &ping:pings){
        double t=(basePos-ping.targetPos)*ping.targetVel/ping.targetVel.moduleSquared();
        if (t<=0){
            continue;
        }
        Vec2 futurePos=ping.targetPos+ping.targetVel*t;
        double distSq= (futurePos - basePos).moduleSquared(); 
        if (distSq>Constants::BASE_RADIUS*Constants::BASE_RADIUS){
            continue;
        }
        double deltaDistance = std::sqrt(Constants::BASE_RADIUS * Constants::BASE_RADIUS - distSq);
        double Ttc = t - (deltaDistance / ping.targetVel.module());

        if (Ttc<minTtc){
            minTtc=Ttc;
            bestTarget=ping;
        }

    }
    return bestTarget;

}

std::optional<double> sol2equation(double a, double b, double c){
    double disc = b * b - 4 * a * c;
    if (disc < 0) return std::nullopt; // No real solution

    double sqrtDisc = std::sqrt(disc);
    double t1 = (-b + sqrtDisc) / (2 * a);
    double t2 = (-b - sqrtDisc) / (2 * a);

    // Smallest positive timen
    if (t1 > 0 && t2 > 0) return std::min(t1, t2);
    if (t1 > 0) return t1;
    if (t2 > 0) return t2;

    return std::nullopt; // Both times negative


}
#include <iostream>
#include "Missile.h"

namespace MissileTrajectory {
    double Calculation::calculateThrust(const Missile& missile, double fuelRamaining) {
        std::cout << "Testando caculateThrust" << std::endl;
        return 0.0;
    }

    double Calculation::calculateDrag(const Missile& missile, double velocity, double airDensity) {
        return 0.5 * airDensity * missile.dragCoefficient * missile.crossSectionalArea * velocity * velocity;
    }

    Position calculateTrajectory(const Missile& missile, double timeStep, double totalTime) {
        Position pos = {0, 0};
        double velocity = 0;
        double airDensity = 1.225;
        
        for (double t = 0; t <= totalTime; t += timeStep) {
            double thrust = calculateThrust(missile, missile.fuelMass);
            double drag = calculateDrag(missile, velocity, airDensity);
            double netForce = thrust - drag - missile.weight * 9.81;
            double acceleration = netForce / missile.weight;
            
            velocity += acceleration * timeStep;
            
            pos.x += velocity * timeStep;
            pos.y += velocity * timeStep;
        }
        
        return pos;
    }

    double calculateFuelRemaining(const Missile& Missile, double time) {
        double fuelConsumptionRate = missile.fuelMass / missile.thrust;
        return missile.fuelMass - (fuelConsumptionRate * time);
    }

    double adjustTrajectoryAngle(const Missile& missile, double targetX, double targetY, const Position& position) {
        double angleToTarget = atan2(targetY - missilePos.y, targetX - missilePos.x);
        return (angleToTarget - currentAngle) * 0.1;
    }

    bool checkImpact(const Position& missilePos, const Position& targetPos, double tolerance) {
        double distance = sqrt(pow(targetPos.x - missilePos.x, 2) + pow(targetPos.y - missilePos.y, 2));
        return distance <= tolerance;
    }

    double estimateTimeToImpact(const Position& missilePos, const Position& targetPos, double velocity) {
        double distance = sqrt(pow(targetPos.x - missilePos.x, 2) + pow(targetPos.y - missilePos.y, 2));
        return distance / velocity;
    }

    bool detectFlare(const Missile& missile, const std::vector<double>& heatSources) {
        for (const auto& source : heatSources) {
            if (source.intensity > missile.sensitivityThreshold && source.speed < thresholdSpeed) {
                return true;
            }
        }
        return false;
    }

    void mitigateFlareImpact(const Missile& missile, Position& targetPosition, const Position& flarePosition) {
        if (detectFlare(missile, heatSources)) {
            targetPosition = missile.previousTargetPosition;
        }
    }

    double detectJammingSignal(const std::vector<double>& radarSignals);

    void mitigateJamming(Missile&missile);

    Position predictEvasiveManeuver(const Position& targetPos, const Position& previousPos);

    void adjustForEvasiveManeuver(Missile& missile, const Position& predictedPos);

    void adjustTrajectoryForEvasion(Missile& missile, const Target& target);

    bool detectStealth(const Radar& radar, const IRScanner& irScanner, const OpticalSystem& optics);

    void mitigateStealth(Missile& missile, const Target& target, const Radar& radar, const IRScanner& irScanner);
    
    void updateMissileNavigation(Missile& missile, const Target& target, Radar& radar, IRScanner& irScanner, OpticalSystem& optics, GPSReceiver& gps, InertialNavigationSystem& ins);
}
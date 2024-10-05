#ifndef MISSILE_H
#define MISSLE_H 

struct Missile {
    double weight;
    double length;
    double diameter;
    double maxSpeed;
    double thrust;
    double dragCoefficient;
    double crossSectionalArea;
    double fuelMass;
};

struct Position {
    double x;
    double y;
};

double caculateThrust(const Missile& missile, double fuelRamaining);
double calculateDrag(const Missile& missile, double velocity, double airDensity);
Position calculateTrajectory(const Missile& missile, double timeStep, double totalTime);
double calculateFuelRemaining(const Missile& Missile, double time);
double adjustTrajectoryAngle(const Missile& missile, double targetX, double targetY, const Position& position);
bool checkImpact(const Position& missilePos, const Position& targetPos, double tolerance);
double estimateTimeToImpact(const Position& missilePos, const Position& targetPos, double velocity);

// Advanced Handling Countermeasures
bool detectFlare(const Missile& missile, const std::vector<double>& heatSources);
void mitigateFlareImpact(Missile& missile);
double detectJammingSignal(const std::vector<double>& radarSignals);
void mitigateJamming(Missile&missile);

#endif
#ifndef MISSILE_H
#define MISSILE_H 

#include <vector>

namespace MissileTrajectory
{
    struct Missile {
        double weight;
        double length;
        double diameter;
        double maxSpeed;
        double thrust;
        double dragCoefficient;
        double crossSectionalArea;
        double fuelMass;

        Missile(double w, double l, double d, double ms, double t, double dc, double csa, double fm)
        : weight(w), length(l), diameter(d), maxSpeed(ms),
          thrust(t), dragCoefficient(dc), crossSectionalArea(csa), fuelMass(fm) {}
    };

    struct Position {
        double x;
        double y;
    };

    struct Target {
        Position currentPosition;
        double currentVelocity;
        double currentAcceleration;
        bool isDecoy;
        
        bool checkIfDecoy() const {
            return isDecoy;
        }
    };

    struct GPSReceiver {
        Position currentPosition;
        double accuracy;
        
        bool isSignalReliable() const {
            return accuracy <= 5.0;
        }
    };

    struct InertialNavigationSystem {
        Position currentPosition;
        double currentVelocity;
        double currentAcceleration;

        void updatePosition(double deltaTime) {
            currentPosition.x += currentVelocity * deltaTime + 0.5 * currentAcceleration * deltaTime * deltaTime;
            currentPosition.y += currentVelocity * deltaTime + 0.5 * currentAcceleration * deltaTime * deltaTime;
        }
    };

    struct Radar {
        double signalStrength;
        double noiseLevel;
        double jammingThreshold;
        double currentFrequency;
        Position detectedPosition;
        
        bool detect() const {
            double snr = signalStrength / noiseLevel;
            return snr > jammingThreshold;
        }

        double nextAvailableFrequency() const {
            return currentFrequency + 0.1;
        }
    };

    struct IRScanner {
        Position detectedPosition;
        double sensitivity;
        double temperatureThreshold;

        bool detect() const {
            return sensitivity >= temperatureThreshold;
        }
    };

    struct OpticalSystem {
        Position detectedPosition;
        double zoomLevel;
        double clarity;
        
        bool detect() const {
            return clarity > 0.8;
        }
    };

    class Calculation {
    public:
        // Trajectory Calculation
        double calculateThrust(const Missile& missile, double fuelRemaining);
        double calculateDrag(const Missile& missile, double velocity, double airDensity);
        Position calculateTrajectory(const Missile& missile, double timeStep, double totalTime);
        double calculateFuelRemaining(const Missile& missile, double time);
        Position predictEvasiveManeuver(const Target& target, double time);
        void adjustTrajectoryForEvasion(Missile& missile, const Target& target);
        bool checkImpact(const Position& missilePos, const Position& targetPos, double tolerance);
        double estimateTimeToImpact(const Position& missilePos, const Position& targetPos, double velocity);

        // Advanced Handling Countermeasures
        bool detectFlare(const Missile& missile, const std::vector<double>& heatSources);
        void mitigateFlare(const Missile& missile, Position& targetPosition, const Position& flarePosition);
        bool detectJamming(const Radar& radar, double signalStrength, double noiseLevel);
        void mitigateJamming(Radar& radar);
       
        bool detectStealth(const Radar& radar, const IRScanner& irScanner, const OpticalSystem& optics);
        void mitigateStealth(Missile& missile, const Target& target, const Radar& radar, const IRScanner& irScanner);
        bool detectDecoy(const std::vector<Target>& targets, const Missile& missile);
        void mitigateDecoy(Missile& missile, std::vector<Target>& targets);
        bool detectGPSSpoofing(const GPSReceiver& gps, const InertialNavigationSystem& ins);
        void mitigateGPSSpoofing(Missile& missile, const GPSReceiver& gps, const InertialNavigationSystem& ins);
    };
}

#endif
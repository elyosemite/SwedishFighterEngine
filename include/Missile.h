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

        // Método para verificar se o alvo é um decoy com base em padrões de movimento
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

        // Muda a frequência de radar para evitar interferência
        double nextAvailableFrequency() const {
            return currentFrequency + 0.1;  // Exemplo simples de mudança de frequência
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
        double calculateThrust(const Missile& missile, double fuelRamaining);
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
        Position predictEvasiveManeuver(const Position& targetPos, const Position& previousPos);
        void adjustForEvasiveManeuver(Missile& missile, const Position& predictedPos);
        void adjustTrajectoryForEvasion(Missile& missile, const Target& target);
        bool detectStealth(const Radar& radar, const IRScanner& irScanner, const OpticalSystem& optics);
        void mitigateStealth(Missile& missile, const Target& target, const Radar& radar, const IRScanner& irScanner);
        void updateMissileNavigation(Missile& missile, const Target& target, Radar& radar, IRScanner& irScanner, OpticalSystem& optics, GPSReceiver& gps, InertialNavigationSystem& ins);
    };
}

#endif
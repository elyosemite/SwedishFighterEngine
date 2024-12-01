#include <iostream>
#include "Missile.h"

namespace MissileTrajectory {
    double Calculation::calculateThrust(const Missile& missile, double fuelRamaining) {
        std::cout << "Testando caculateThrust" << std::endl;
        return 0.0;
    }

    double Calculation::calculateDrag(const Missile& missile, double velocity, double airDensity) {
        std::cout << "Testando calculateDrag" << std::endl;
        return 0.5 * airDensity * missile.dragCoefficient * missile.crossSectionalArea * velocity * velocity;
    }
}
#ifndef MISSILEGEOMETRY_H
#define MISSILEGEOMETRY_H

#include "MathOperations.h"

namespace MissileGeometry {
    class Geometry {
    public:
        double calculateRectangleArea(int widthg, int height);
        double calculateCircleArea(double radius);
    };
}

#endif
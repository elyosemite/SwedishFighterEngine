#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "MathOperations.h"

namespace MissileGeometry {
    class Geometry {
    public:
        double calculateRectangleArea(int widthg, int height);
        double calculateCircleArea(double radius);
    };
}

#endif
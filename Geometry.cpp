#include "Geometry.h"
#include <cmath>

namespace MissileGeometry {
    double Geometry::calculateRectangleArea(int width, int height) {
        MathOperations math;
        return static_cast<double>(math.mult(width, height));
    }

    double Geometry::calculateCircleArea(double radius) {
        return 3.14159265358979323846 * std::pow(radius, 2);
    }
}

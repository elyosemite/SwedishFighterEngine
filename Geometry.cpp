#include "Geometry.h"
#include <cmath>

double Geometry::calculateRectangleArea(int width, int height) {
    MathOperations math;
    return math.mult(width, height);
}

double Geometry::calculateCircleArea(double radius) {
    return 3.14159265358979323846 * std::pow(radius, 2);
}
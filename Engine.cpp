#include <iostream>
#include <vector>
#include <fmt/core.h>

#include "Geometry.h"
#include "Missile.h"

using namespace MissileGeometry;
using namespace MissileTrajectory;

namespace MyNamespace {
	int value = 42;

	void displayvalue() {
		std::cout << "Value: " << value << std::endl;
	}
}

int main() {
	fmt::print("Hello World!\n");

	std::cout << "Swedish Fighter Engine is flying in the sky." << std::endl;

	Geometry geo;

	double rectangleArea = geo.calculateRectangleArea(5, 5);
	//double circleArea = geo.calculateCircleArea(4.5);

	std::cout << "Reactangle Area : " << rectangleArea << std::endl;
	//std::cout << "Circle Area : " << circleArea << std::endl;

	// double weight;
	// double length;
	// double diameter;
	// double maxSpeed;
	// double thrust;
	// double dragCoefficient;
	// double crossSectionalArea;
	// double fuelMass;

	Calculation calc;
	Missile missile = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
	std::cout << calc.calculateThrust(missile, 8.9) << std::endl;

	MyNamespace::displayvalue();

	return 0;
}
#include <iostream>

#include "Geometry.h"

namespace MyNamespace {
	int value = 42;

	void displayvalue() {
		std::cout << "Value: " << value << std::endl;
	}
}

int main() {
	std::cout << "Swedish Fighter Engine is flying in the sky." << std::endl;

	Geometry geo;

	double rectangleArea = geo.calculateRectangleArea(5, 5);
	double circleArea = geo.calculateCircleArea(4.5);

	std::cout << "Reactangle Area : " << rectangleArea << std::endl;
	std::cout << "Circle Area : " << circleArea << std::endl;

	MyNamespace::displayvalue();

	return 0;
}
#include <iostream>

#include "SimpleExample.h"

int main() {
	std::cout << "Swedish Fighter Engine is flying in the sky." << std::endl;

	SimpleExample calculator;

	std::cout << calculator.sum(10, 10) << std::endl;
	std::cout << calculator.divide(10, 10) << std::endl;
	std::cout << calculator.mult(10, 10) << std::endl;
	std::cout << calculator.subtract(10, 10) << std::endl;

	return 0;
}
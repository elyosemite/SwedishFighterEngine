#include <iostream>

#include <alpha/alpha.h>

int main() {
	// Alpha module

	Alpha::AlphaComponent component(42, "ExampleComponent");
	Alpha::AlphaUseCase useCase;

	std::cout << useCase.calculate(component, true);

	return 0;
}

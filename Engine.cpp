#include <iostream>

#include <alpha/alpha.h>
#include <beta/beta.h>
#include <gamma/gamma.h>

int main() {
	// Alpha module

	Alpha::AlphaComponent alphaComponent(42, "ExampleComponent alpha");
	Alpha::AlphaUseCase alphaUseCase;

	std::cout << "Executing Alpha module for searching target: " << alphaUseCase.calculate(alphaComponent, true) << std::endl;

	// Beta module

	Beta::BetaComponent betaComponent(58, "ExampleComponent beta");
	Beta::BetaUseCase betaUseCase;

	std::cout  << "Executing Beta module for preparing missiles system: " << betaUseCase.calculate(betaComponent, true) << std::endl;

	// Gamma module

	Gamma::GammaComponent gammaComponent(38, "ExampleComponent gamma");
	Gamma::GammaUseCase gammaUseCase;

	std::cout  << "Executing Gamma module for stripe our targets: " << gammaUseCase.calculate(gammaComponent, true) << std::endl;

	return 0;
}

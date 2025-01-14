#include <iostream>
#include <cmath>
#include <vector>

#include <alpha/alpha.h>
#include <beta/beta.h>
#include <gamma/gamma.h>
#include <concurrency/concurrency.h>

template <typename T>
T calcularJurosCompostos(T principal, T taxa, int periodo)
{
	return principal * std::pow(1 + taxa, periodo);
}

template <typename T>
class Portfolio
{
private:
	std::vector<T> investimentos;

public:
	void adicionarInvestimento(const T& investimento)
	{
		investimentos.push_back(investimento);
	}

	void mostrarInvestimentos() const
	{
		for (auto &investimento : investimentos)
		{
			std::cout << investimento << std::endl;
		}
	}
};

int main()
{
	double principal = 1000.0;
	double taxa = 0.05;
	int periodo = 10;

	Concurrency::Thams thams;
	thams.Foo();

	double resultado = calcularJurosCompostos(principal, taxa, periodo);
	std::cout << "Montante final: " << resultado << std::endl;

	// Template com classes
	Portfolio<std::string> portfolio;

	portfolio.adicionarInvestimento("Asset: AAPL");
	portfolio.adicionarInvestimento("treasury bond: Tesouro Direto");
	portfolio.adicionarInvestimento("Cryptocurrency: Bitcoin");

	std::cout << "Investimentos no Portfolio:" << std::endl;

	portfolio.mostrarInvestimentos();

	return 0;
}

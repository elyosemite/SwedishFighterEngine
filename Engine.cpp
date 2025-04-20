#include <iostream>
#include <fmt/core.h>
#include <nlohmann/json.hpp>

#include <concurrency/concurrency.h>

using json = nlohmann::json;

int main()
{
	fmt::print("Hello, {}\n", "Thamirys");

	// Cria um objeto JSON
    json dados = {
        {"nome", "João"},
        {"idade", 30},
        {"hobbies", {"ler", "correr", "programar"}}
    };

    // Serializa para string
    std::string json_str = dados.dump(4);  // Indentação de 4 espaços

    // Imprime
    std::cout << "JSON Gerado:\n" << json_str << std::endl;
	
	return 0;
}

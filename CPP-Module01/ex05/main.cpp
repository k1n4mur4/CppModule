#include "Harl.hpp"

int main() {
	Harl harl;
		
	std::cout << "========================================" << std::endl;
	std::cout << "      Harl 2.0 - Complaint System" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << std::endl;

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		std::cout << "Level: " << levels[i] << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		harl.complain(levels[i]);
		std::cout << std::endl;
	}

	std::cout << "Testing invalid level:" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	harl.complain("INVALID");
	std::cout << "(No output expected for invalid level)" << std::endl;
	std::cout << std::endl;

	std::cout << "Multiple complaints:" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	harl.complain("ERROR");
	harl.complain("ERROR");
	harl.complain("WARNING");

	return 0;
}

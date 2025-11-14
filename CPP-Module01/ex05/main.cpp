#include "Harl.hpp"

int	main(void) {
	Harl	harl;

	std::cout << "" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;

	harl.complain("WARNING");
	std::cout << std::endl;

	harl.complain("INFO");
	std::cout << std::endl;

	harl.complain("DEBUG");
	std::cout << std::endl;

	harl.complain("something else");
	std::cout << std::endl;

	std::cout << "Now you have 5 chances to make harl say something." << std::endl;

	for (int i = 0; i < 5; i++) {
		std::cout << "input: ";
		std::string	input;
		std::getline(std::cin, input);
		if (std::cin.eof() == true) {
			std::cerr << "^D" << std::endl;
			return 1;
		}
		harl.complain(input);
		std::cout << std::endl;
	}
	return 0;
}

#include "Harl.hpp"

int	main(int argc, char *argv[]) {

	if (argc != 2)
	{
		std::cout << "invalid command" << std::endl;
		return 1;
	}

	Harl	harl;

	harl.complain(argv[1]);
	std::cout << std::endl;

	return 0;
}

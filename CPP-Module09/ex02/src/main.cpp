#include "PmergeMe.hpp"

namespace Color {
	const char *BOLD = "\033[1m";
	const char *BOLD_UNDERLINE = "\033[1;4m";
	const char *BOLD_RED = "\033[1;31m";
	const char *RESET = "\033[0m";
}

static void error(std::string msg) {
	std::cerr << Color::BOLD_RED << "Error:" << Color::RESET << " " << msg << std::endl;
}

int	main(int argc, char *argv[]) {
	PmergeMe	merge = PmergeMe();

	if (argc == 1) {
		error("invalid arguments");
		return 1;
	}

	try {
		merge.sortAll(argc, argv);
	} catch (std::exception &e) {
		error(e.what());
		return 1;
	}
}

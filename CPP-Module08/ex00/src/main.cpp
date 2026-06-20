#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

namespace Color {
	const char *BOLD = "\033[1m";
	const char *BOLD_UNDERLINE = "\033[1;4m";
	const char *RESET = "\033[0m";
}

static void usage(const char *command, const char * const *options) {
	std::cout << Color::BOLD_UNDERLINE << "Usage:" << Color::RESET
		<< " " << Color::BOLD << command << Color::RESET;
	for (size_t i = 0; options[i] != NULL; ++i) {
		std::cout << " " << options[i];
	}
	std::cout << std::endl;
}

int main(int argc, char *argv[] ) {

	// option
	char const *command = argv[0];
	if (argc < 3) {
		const char *opts[] = {"<value>", "<vector>", NULL};
		usage(command, opts);
		return 1;
	}

	int value = std::atoi(argv[1]);

	std::vector<int> vec;
	vec.reserve(argc - 2);
	for (int i = 2; i < argc; ++i)
		vec.push_back(std::atoi(argv[i]));

	#ifdef TEST
		std::cout << "===== VECTOR =====" << std::endl;
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	#endif

	std::cout << "===== Easy Find =====" << std::endl;

	try {
		std::vector<int>::iterator iter = easyfind(vec, value);
		std::cout << "Found " << *iter << " at index "
				<< (iter - vec.begin()) << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

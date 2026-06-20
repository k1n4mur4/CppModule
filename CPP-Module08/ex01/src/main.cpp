#include "Span.hpp"
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

int main(int argc, char *argv[]) {

	// option
	char const *command = argv[0];
	if (argc < 3) {
		const char *opts[] = {"<size>", "<numbers...>", NULL};
		usage(command, opts);
		return 1;
	}

	unsigned int size = static_cast<unsigned int>(std::atoi(argv[1]));
	Span sp(size);

	#ifdef TEST
		std::cout << "===== NUMBERS =====" << std::endl;
	#endif
	for (int i = 2; i < argc; ++i) {
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "===== Span =====" << std::endl;
	try {
		for (int i = 2; i < argc; ++i)
			sp.addNumber(std::atoi(argv[i]));

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

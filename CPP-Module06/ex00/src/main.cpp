#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

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
	if (argc != 2) {
		const char *opts[] = {"<literal>", NULL};
		usage("./convert", opts);
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

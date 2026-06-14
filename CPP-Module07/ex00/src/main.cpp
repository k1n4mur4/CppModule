#include "whatever.hpp"
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

int main(int argc, char *argv[] ) {

	if (argc == 1) {
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

		return 0;
	}

	// option
	char const *command = argv[0];
	if (argc > 3 || argc == 2) {
		const char *opts[] = {"x", "y", NULL};
		usage(command, opts);
		return 1;
	}

	#ifndef TEST
		std::cout << "===== Option =====" << std::endl;
	#endif

	std::string x = argv[1];
	std::string y = argv[2];

	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
	std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl;

	return 0;
}

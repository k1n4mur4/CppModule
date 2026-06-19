#include "iter.hpp"
#include <iostream>
#include <cstddef>   // size_t
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

	if (argc < 2) {
		char const *command = argv[0];
		const char *opts[] = {"<str>", "[str ...]", NULL};
		usage(command, opts);
		return 1;
	}

	size_t length = static_cast<size_t>(argc - 1);
	#ifndef TEST
		std::cout << "===== Length: " << length << " =====" << std::endl;
	#endif

	std::string *strArr = new std::string[length];
	for (size_t i = 0; i < length; i++) {
		strArr[i] = argv[i + 1];
	}
	std::cout << "--- STRING ---" << std::endl;
	iter(strArr, length, printElm<std::string>);
	delete[] strArr;

	int *arr = new int[length];
	for (size_t i = 0; i < length; i++) {
		arr[i] = static_cast<int>(i);
	}

	std::cout << "--- INT ---" << std::endl;

	std::cout << "- print -" << std::endl;
	iter(arr, length, printElm<int>);
	std::cout << "- twice -" << std::endl;
	iter(arr, length, twice<int>);
	std::cout << "- print -" << std::endl;
	iter(arr, length, printElm<int>);

	delete[] arr;

	return 0;
}

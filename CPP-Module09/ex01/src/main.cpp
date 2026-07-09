#include "RPN.hpp"
#include <iostream>
#include <cctype>

namespace Color {
	const char *BOLD = "\033[1m";
	const char *BOLD_UNDERLINE = "\033[1;4m";
	const char *BOLD_RED = "\033[1;31m";
	const char *RESET = "\033[0m";
}

static void error(std::string msg) {
	std::cerr << Color::BOLD_RED << "Error:" << Color::RESET << " " << msg << std::endl;
}

int main(int argc, char *argv[]) {

	if (argc != 2) {
		error("invalid argument");
		return 1;
	}

	char	*input = argv[1];
	RPN		rpn = RPN();

	for (int i = 0; input[i]; ++i) {
		if (input[i] == ' ')
			continue;

		#ifdef DEBUG
			std::cout << Color::BOLD << "----- DEBUG MODE -----" << Color::RESET << std::endl;
		#endif
		if (rpn.is_command(input[i])) {
			try {
				rpn.run_command(input[i]);
			} catch (std::exception &e) {
				error(e.what());
				return 1;
			}
			// #ifdef DEBUG
			// 	std::cout << "command:" << input[i] << std::endl;
			// #endif
		} else if (isdigit(static_cast<unsigned char>(input[i]))) {
			int	n = input[i] - '0';
			rpn.set_stack(n);
			// #ifdef DEBUG
			// 	std::cout << "input:" << n << std::endl;
			// #endif
		} else {
			error("invalid arguments");
			return 1;
		}
		// #ifdef DEBUG
			// int ret = rpn.get_stack();
			// std::cout << "ret:" << ret << std::endl;
			// rpn.set_stack(ret);
		// #endif
	}

	try {
		int	result = rpn.get_stack();
		if (!rpn.isEmpty())
			throw std::runtime_error("too many operands");
		std::cout << result << std::endl;
	} catch (std::exception &e) {
		error(e.what());
		return 1;
	}

	return 0;
}

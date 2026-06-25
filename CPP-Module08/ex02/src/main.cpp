#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <cstdlib>


namespace Color {
	const char *BOLD = "\033[1m";
	const char *BOLD_UNDERLINE = "\033[1;4m";
	const char *RESET = "\033[0m";
}

static bool isNumber(const char *s) {
	if (s == NULL || *s == '\0')
		return false;
	if (*s == '+' || *s == '-')
		++s;
	if (*s == '\0')
		return false;
	for (; *s != '\0'; ++s)
		if (*s < '0' || *s > '9')
			return false;
	return true;
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


	if (argc == 1) {
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		const MutantStack<int> cstack(mstack);

		MutantStack<int>::const_iterator cit = cstack.begin();
		MutantStack<int>::const_iterator cite = cstack.end();

		while (cit != cite) {
			std::cout << *cit << std::endl;
			++cit;
		}

		std::stack<int> s(mstack);
		return 0;
	}

	// option
	char const *command = argv[0];
	for (int i = 1; i < argc; ++i) {
		if (!isNumber(argv[i])) {
			const char *opts[] = {"<numbers...>", NULL};
			usage(command, opts);
			return 1;
		}
	}

	MutantStack<int> mstack;
	for (int i = 1; i < argc; ++i)
		mstack.push(std::atoi(argv[i]));

	std::cout << "===== MutantStack =====" << std::endl;
	std::cout << "top:  " << mstack.top() << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;

	std::cout << "----- iterator -----" << std::endl;

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	const MutantStack<int> cstack(mstack);

	std::cout << "----- const_iterator -----" << std::endl;
	for (MutantStack<int>::const_iterator cit = cstack.begin(); cit != cstack.end(); ++cit)
		std::cout << *cit << std::endl;

	std::stack<int> s(mstack);

	std::cout << "----- std::stack copy -----" << std::endl;
	std::cout << "size: " << s.size() << std::endl;

	return 0;
}

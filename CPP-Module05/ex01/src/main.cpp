#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	// success
	try {
		Bureaucrat b("Alice", 50);
		Form f("FormA", 75, 50);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// error
	// high
	try {
		Bureaucrat b("Bob", 100);
		Form f("high", 50, 50);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// low
	try {
		Form f("low", 0, 50);
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}

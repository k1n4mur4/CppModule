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
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// not signed
	try {
		Bureaucrat b("Bob", 100);
		Form f("FormB", 75, 50);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Float
	try {
		Bureaucrat b("Float", 50.0);
		Form f("FloatForm", 75.0, 50.0);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// error
	// high
	try {
		Form f("High", 0, 50);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	// low
	try {
		Form f("Low", 151, 50);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}

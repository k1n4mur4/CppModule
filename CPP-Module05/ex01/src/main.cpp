#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	// Success
	// Signed
	try {
		std::cout << "=======Signed======" << std::endl;
		Bureaucrat b("Signed", 50);
		Form f("Signed", 75, 50);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
		std::cout << "===================" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// not Signed
	try {
		std::cout << "=======Signed======" << std::endl;
		Bureaucrat b("Bad", 100);
		Form f("Bad", 75, 0);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
		std::cout << "===================" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Float
	try {
		std::cout << "========Float======" << std::endl;
		Bureaucrat b("Float", 50.0);
		Form f("Float", 75, 50.0);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
		std::cout << "===================" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Error
	// High
	try {
		std::cout << "========high=======" << std::endl;
		Bureaucrat b("High", 100);
		Form f("High", 50, 50);
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
		std::cout << "===================" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Low
	try {
		std::cout << "========Low=======" << std::endl;
		Bureaucrat b("Low", 100);
		// std::cout << "===================" << std::endl; /* write */
		Form f("Low", 0, 50);
		// std::cout << "===================" << std::endl; /* don't write */
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
		std::cout << "===================" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}

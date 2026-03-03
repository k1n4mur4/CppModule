#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	srand(time(0));

	// ShrubberyCreationForm
	try {
		Bureaucrat b("Alice", 137);
		ShrubberyCreationForm f("home");
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// RobotomyRequestForm
	try {
		Bureaucrat b("Bob", 45);
		RobotomyRequestForm f("Bender");
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// PresidentialPardonForm
	try {
		Bureaucrat b("Charlie", 5);
		PresidentialPardonForm f("Marvin");
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	srand(time(0));

	// success
	// ShrubberyCreationForm
	try {
		Bureaucrat b("Alice", 137);
		ShrubberyCreationForm f("home");
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// RobotomyRequestForm
	try {
		Bureaucrat b("Bob", 45);
		RobotomyRequestForm f("Bender");
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// PresidentialPardonForm
	try {
		Bureaucrat b("Charlie", 5);
		PresidentialPardonForm f("Marvin");
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// error
	// not signed
	try {
		Bureaucrat b("Dave", 1);
		RobotomyRequestForm f("Target");
		b.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// sign grade too low
	try {
		Bureaucrat b("Eve", 150);
		ShrubberyCreationForm f("garden");
		b.signForm(f);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// exec grade too low
	try {
		Bureaucrat b("Frank", 140);
		ShrubberyCreationForm f("park");
		b.signForm(f);
		b.executeForm(f);
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}

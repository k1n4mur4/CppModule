#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	srand(time(0));

	// success
	// robotomy request
	try {
		Intern someIntern;
		AForm* rrf = someIntern.makeForm("robotomy request", "Bender");
		Bureaucrat b("Alice", 1);
		b.signForm(*rrf);
		b.executeForm(*rrf);
		delete rrf;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// shrubbery creation
	try {
		Intern someIntern;
		AForm* scf = someIntern.makeForm("shrubbery creation", "home");
		Bureaucrat b("Bob", 1);
		b.signForm(*scf);
		b.executeForm(*scf);
		delete scf;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// presidential pardon
	try {
		Intern someIntern;
		AForm* ppf = someIntern.makeForm("presidential pardon", "Marvin");
		Bureaucrat b("Charlie", 1);
		b.signForm(*ppf);
		b.executeForm(*ppf);
		delete ppf;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// error
	// unknown form
	try {
		Intern someIntern;
		AForm* f = someIntern.makeForm("unknown form", "nobody");
		if (f)
			delete f;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// sign grade too low
	try {
		Intern someIntern;
		AForm* f = someIntern.makeForm("presidential pardon", "Target");
		Bureaucrat b("Dave", 150);
		b.signForm(*f);
		delete f;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// exec grade too low
	try {
		Intern someIntern;
		AForm* f = someIntern.makeForm("presidential pardon", "Target");
		Bureaucrat b("Eve", 20);
		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}

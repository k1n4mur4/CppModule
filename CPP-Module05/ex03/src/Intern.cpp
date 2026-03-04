#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

struct	FormEntry {
	std::string name;
	AForm* (*create)(const std::string & target);
};

static AForm*	createShrubbery(const std::string & target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string & target) {
	return new RobotomyRequestForm(target);
}
static AForm* createPardon(const std::string & target) {
	return new PresidentialPardonForm(target);
}

FormEntry forms[] = {
	{"shrubbery creation", createShrubbery},
	{"robotomy request",   createRobotomy},
	{"presidential pardon", createPardon}
};


Intern::Intern(){
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern(){
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &other){
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other){
	(void)other;
	return *this;
}


AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
	size_t	size = sizeof(forms) / sizeof(forms[0]);

	for (size_t idx = 0; idx < size; idx++) {
		if (forms[idx].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return forms[idx].create(target);
		}
	}

	std::cout << "Error: Form '" << formName << "' does not exist." << std::endl;
	return NULL;
}

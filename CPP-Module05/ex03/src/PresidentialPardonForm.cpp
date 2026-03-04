#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target_(target){
	std::cout << "PresidentialPardonForm parameterized constructor called: " << target_ << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called: " << target_ << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target_(other.target_) {
	std::cout << "PresidentialPardonForm copy constructor called: " << target_ << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target_ = other.target_;
	}
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getIsSign())
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();

	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


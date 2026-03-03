#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target_(target){
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target_(other.target_) {
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


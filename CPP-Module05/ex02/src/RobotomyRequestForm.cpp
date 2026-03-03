#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target_(target) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target_(other.target_){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target_ = other.target_;
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getIsSign())
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > getExecGrade()) 
		throw AForm::GradeTooLowException();

	std::cout << "Drrrrrrrr... *drilling noises*" << std::endl;

	if (rand() % 2 == 0)
		std::cout << target_ << " has been robotomized." << std::endl;
	else
		std::cout << target_ << " robotomy failed." << std::endl;

}

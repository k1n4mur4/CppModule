#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target_(target){
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target_(other.target_) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target_ = other.target_;
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getIsSign())
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();

	std::ofstream file((target_ + "_shrubbery").c_str());
	file << "     *     " << std::endl;
	file << "    ***    " << std::endl;
	file << "   *****   " << std::endl;
	file << "    |||    " << std::endl;
}

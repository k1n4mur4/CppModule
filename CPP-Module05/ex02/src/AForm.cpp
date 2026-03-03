#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name_("default"), isSign_(false), signGrade_(1), execGrade_(1) {
	std::cout << "called AForm constractor." << std::endl;
}

AForm::~AForm() {
	std::cout << "called AForm destractor." << std::endl;
}

AForm::AForm(const std::string name, int signGrade, int execGrade): name_(name), isSign_(false), signGrade_(signGrade), execGrade_(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) :name_(other.name_), isSign_(other.isSign_), signGrade_(other.signGrade_), execGrade_(other.execGrade_) {
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		this->isSign_ = other.isSign_;
	}
	return *this;
}

std::string	AForm::getName(void) const {
	return this->name_;
}

bool		AForm::getIsSign(void) const {
	return this->isSign_;
}

int			AForm::getSignGrade(void) const {
	return this->signGrade_;
}

int			AForm::getExecGrade(void) const {
	return this->execGrade_;
}

void		AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->signGrade_)
		throw GradeTooLowException();
	this->isSign_ = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &f) {
	os << "AForm: " << f.getName() << ", "
		<< "Signed: " << f.getIsSign() << ", "
		<< "Sign Grade: " << f.getSignGrade() << ", "
		<< "Exec Grade: " << f.getExecGrade();
	return os;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low.";
}

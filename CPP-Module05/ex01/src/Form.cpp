#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name_("default"), isSign_(false), signGrade_(1), execGrade_(1) {
	std::cout << "called Form constractor." << std::endl;
}

Form::~Form() {
	std::cout << "called Form destractor." << std::endl;
}

Form::Form(const std::string name, int signGrade, int execGrade): name_(name), isSign_(false), signGrade_(signGrade), execGrade_(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) :name_(other.name_), isSign_(other.isSign_), signGrade_(other.signGrade_), execGrade_(other.execGrade_) {
}

Form &Form::operator=(const Form &other) {
	if (this != &other) {
		this->isSign_ = other.isSign_;
	}
	return *this;
}

std::string	Form::getName(void) const {
	return this->name_;
}

bool		Form::getIsSign(void) const {
	return this->isSign_;
}

int			Form::getSignGrade(void) const {
	return this->signGrade_;
}

int			Form::getExecGrade(void) const {
	return this->execGrade_;
}

void		Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->signGrade_)
		throw GradeTooLowException();
	this->isSign_ = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f) {
	os << "Form: " << f.getName() << ", "
		<< "Signed: " << f.getIsSign() << ", "
		<< "Sign Grade: " << f.getSignGrade() << ", "
		<< "Exec Grade: " << f.getExecGrade();
	return os;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low.";
}

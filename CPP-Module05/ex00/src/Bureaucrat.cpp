#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("default"), grade_(1) {
	std::cout << "called Bureaucrat constractor." << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "called Bureaucrat destractor." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name), grade_(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.name_), grade_(other.grade_) {
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other) {
	if (this != &other)
		this->grade_ = other.grade_;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat & b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

std::string Bureaucrat::getName(void) const {
	return this->name_;
}

int			Bureaucrat::getGrade(void) const {
	return this->grade_;
}


void Bureaucrat::incrementGrade() {
	if (this->grade_ <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade_--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade_ >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade_++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

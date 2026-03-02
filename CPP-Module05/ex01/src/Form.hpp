#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
	public:
		Form();
		~Form();
		Form(const std::string name, int signGrade, int execGrade);
		Form(const Form &other);

		Form &operator=(const Form &other);

		std::string	getName() const;
		bool		getIsSign() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		void		beSigned(const Bureaucrat & b);

		class GradeTooHighException: public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char *what() const throw();
		};

	private:
		const std::string	name_;
		bool				isSign_;
		const int			signGrade_;
		const int			execGrade_;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif

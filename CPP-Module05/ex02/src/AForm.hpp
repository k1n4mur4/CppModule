#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
	public:
		AForm();
		virtual	~AForm();
		AForm(const std::string name, int signGrade, int execGrade);
		AForm(const AForm &other);
		virtual	void	execute(Bureaucrat const &executor) const = 0;

		AForm &operator=(const AForm &other);

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

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif

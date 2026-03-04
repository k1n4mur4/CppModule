#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class	AForm;

class	Bureaucrat{
	public:
		Bureaucrat();
		~Bureaucrat();

		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);

		Bureaucrat &operator=(const Bureaucrat & other);
		
		std::string getName () const;
		int			getGrade() const;

		void	incrementGrade();
		void	decrementGrade();

		void	signForm(AForm &f);
		void	executeForm(AForm const &form);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

	private:
		const std::string	name_;
		int					grade_;
};

std::ostream & operator<<(std::ostream & os, const Bureaucrat & b);
	
#endif

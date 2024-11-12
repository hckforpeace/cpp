#ifndef BUREACRAT_HPP
# define BUREACRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int			_grade;
	public:
		// Canonical AForm
		Bureaucrat(std::string name, int grade);
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat& operator=(const Bureaucrat &copy);

		// Exceptions
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		// Getters
		std::string getName(void) const;
		int getGrade(void) const;

		// Change grade
		void	incrementGrade();
		void	decrementGrade();

		// sign form
		void	signForm(AForm& form) const;

		// execute form
		void executeForm(AForm const & form);
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& obj);

#endif

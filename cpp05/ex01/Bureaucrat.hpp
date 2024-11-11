#ifndef BUREACRAT_HPP
# define BUREACRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string _name;
		int			_grade;
	public:
		// Canonical Form
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
		void	signForm(Form& form) const;
};


#endif
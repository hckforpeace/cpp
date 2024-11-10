#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool	_isSigned;
		const int	_gradeSign;
		const int	_gradeExec;
	public:
		// Canonic Form
		Form();
		~Form();
		Form(std::string name, const int gradeSign, const int gradeExec);
		Form(const Form& copy);
		Form&	operator=(const Form& copy);

		// Getters
		int getGradeSign() const;
		int getGradeExec() const;
		std::string getName() const;
		bool getIsSign() const;

		class GradeTooHighException: public std::exception
		{
			const char * what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			const char * what() const throw();
		};

		void	beSigned(const Bureaucrat& obj);

};

#endif
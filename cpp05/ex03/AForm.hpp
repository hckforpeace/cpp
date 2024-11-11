#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool	_isSigned;
		const int	_gradeSign;
		const int	_gradeExec;
	public:
		// Canonic AForm
		AForm();
		virtual ~AForm();
		AForm(std::string name, const int gradeSign, const int gradeExec);
		AForm(const AForm& copy);
		AForm&	operator=(const AForm& copy);

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

		class FormNotSignedException: public std::exception
		{
			const char * what() const throw();
		};

		void	beSigned(const Bureaucrat& obj);
		
		// Execute
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream&	operator<<(std::ostream &stream, AForm &form);


#endif
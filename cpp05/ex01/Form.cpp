#include "Form.hpp"

/* ************************************************************************** */
/*                             Canonical Form                                 */
/* ************************************************************************** */
Form::Form():_name("Polution"), _isSigned(false), _gradeSign(75), _gradeExec(75)
{
	std::cout << "Default form constructor was called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(std::string name, const int gradeSign, const int gradeExec):_name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << "Form constructor was called" << std::endl;
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& copy):_name(copy.getName()),_isSigned(copy.getIsSign()), _gradeSign(copy.getGradeSign()), _gradeExec(copy.getGradeExec())
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = copy;
}


Form& Form::operator=(const Form& copy)
{
	std::cout << "Form assignment constructor called" << std::endl;
	if (this == &copy)
		return (*this);
	return *this;
}

/* ************************************************************************** */
/*                             Getters                                        */
/* ************************************************************************** */
int Form::getGradeSign() const
{
	return (this->_gradeSign);
}
int Form::getGradeExec() const
{
	return (this->_gradeExec);
}
std::string Form::getName() const
{
	return (this->_name);
}
bool Form::getIsSign() const
{
	return (this->_isSigned);
}

/* ************************************************************************** */
/*                             Exceptions                             		  */
/* ************************************************************************** */
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}


void	Form::beSigned(const Bureaucrat& obj)
{
	if (obj.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::ostream&	operator<<(std::ostream &stream, Form &form)
{
	stream << "Name: " << form.getName()
	<< " IsSigned: " << form.getIsSign()
	<< " Grade Execution: " << form.getGradeExec()
	<< " Grade Signature: " << form.getGradeSign() <<std::endl;
	return (stream);
}


#include "AForm.hpp"

/* ************************************************************************** */
/*                             Canonical AForm                                 */
/* ************************************************************************** */
AForm::AForm():_name("Polution"), _isSigned(false), _gradeSign(75), _gradeExec(75)
{
	std::cout << "Default form constructor was called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(std::string name, const int gradeSign, const int gradeExec):_name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << "AForm constructor was called" << std::endl;
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& copy):_name(copy.getName()),_isSigned(copy.getIsSign()), _gradeSign(copy.getGradeSign()), _gradeExec(copy.getGradeExec())
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = copy;
}


AForm& AForm::operator=(const AForm& copy)
{
	std::cout << "AForm assignment constructor called" << std::endl;
	if (this == &copy)
		return (*this);
	return *this;
}

/* ************************************************************************** */
/*                             Getters                                        */
/* ************************************************************************** */
int AForm::getGradeSign() const
{
	return (this->_gradeSign);
}
int AForm::getGradeExec() const
{
	return (this->_gradeExec);
}
std::string AForm::getName() const
{
	return (this->_name);
}
bool AForm::getIsSign() const
{
	return (this->_isSigned);
}

/* ************************************************************************** */
/*                             Exceptions                             		  */
/* ************************************************************************** */
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form Not Signed");
}

void	AForm::beSigned(const Bureaucrat& obj)
{
	if (obj.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::ostream&	operator<<(std::ostream &stream, AForm &form)
{
	stream << "Name: " << form.getName()
	<< ", IsSigned: " << form.getIsSign()
	<< ", Grade Execution: " << form.getGradeExec()
	<< ", Grade Signature: " << form.getGradeSign();
	return (stream);
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSign() == false)
		throw (FormNotSignedException());
	else if (executor.getGrade() > this->getGradeExec())
		throw (GradeTooLowException());
}

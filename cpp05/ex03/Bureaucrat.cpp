#include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                             Canonical Form                                 */
/* ************************************************************************** */
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat():_name("Alan"), _grade(1)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade > 150)
		throw(GradeTooLowException());
	else if (grade < 1)
		throw(GradeTooHighException());
	this->_grade = grade;
	this->_name = name;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = b;
}
Bureaucrat&  Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat assignment constructor called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_grade = copy.getGrade();
	this->_name = copy.getName();
	return (*this);
}


/* ************************************************************************** */
/*                             Exceptions                             		  */
/* ************************************************************************** */
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error the grade is too High !!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error the grade is too Low !!");
}

/* ************************************************************************** */
/*                             	Getters                             		  */
/* ************************************************************************** */
int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

// Increment Grade
void	Bureaucrat::incrementGrade()
{
	if (this->getGrade() - 1 < 1)
		throw(GradeTooHighException());
	this->_grade -= 1;
}

// Decrement Grade
void	Bureaucrat::decrementGrade()
{
	if (this->getGrade() + 1 > 150)
		throw(GradeTooLowException());
	this->_grade++;
}

// Overload Display
std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& obj)
{
	stream << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (stream);
}

void	Bureaucrat::signForm(AForm &form) const
{
	if (form.getIsSign())
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because it's already signed" << std::endl;
	else
	{
		try
		{
			form.beSigned(*this);
		}
		catch(const std::exception& e)
		{
			std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what()<< std::endl;
			return ;
		}
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Execution has failed because " << e.what() << std::endl;
	}
	
}


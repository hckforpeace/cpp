#include "Bureaucrat.hpp"

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


// Eceptions
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error the grade is too High !!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error the grade is too Low !!");
}

// Getters
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
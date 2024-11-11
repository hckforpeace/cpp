#include "RobotomyRequestForm.hpp"

/* ************************************************************************** */
/*                             Constructors/Destructor                        */
/* ************************************************************************** */
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequest Form destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", SIGNGRADE, EXECGRADE), _target("default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;

}

/**
 * @brief SIGNGRADE 72 EXECGRADE 45
 */
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", SIGNGRADE, EXECGRADE), _target(target)
{
	std::cout << "RobotomyRequest Form constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm("RobotomyRequestForm", SIGNGRADE, EXECGRADE)
{
	std::cout << "RobotomyRequest Form copy constructor called" << std::endl;
	*this = copy;
}

/* ************************************************************************** */
/*                             Overload Operators                             */
/* ************************************************************************** */
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this == &copy)
		return (*this);
	this->_target = copy.getTarget();
	return (*this);
}

/* std::ostream& operator<<(std::ostream& stream, const RobotomyRequestForm &obj)
{
	stream << obj << " Target: " << obj.getTarget() << std::endl;
	return (stream);
} */

/* ************************************************************************** */
/*                             public member functions                        */
/* ************************************************************************** */
std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::srand(time(0));
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomised successfully" << std::endl;
	else
		std::cout << "Robotomisation has failed" << std::endl;
}
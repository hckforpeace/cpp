#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*                             Constructors                                   */
/* ************************************************************************** */

/**
 * @brief SHRU_SIGNGRADE 145 SHRU_EXECGRADE 137
 */
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", SHRU_SIGNGRADE, SHRU_EXECGRADE), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", SHRU_SIGNGRADE, SHRU_EXECGRADE), _target("home")
{
	std::cout << "ShrubberyCreationForm constructor called " << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):AForm(copy)
{
	std::cout << "ShrubberyCreationForm copy constructor called " << std::endl;
	*this = copy; 
}

/* ************************************************************************** */
/*                             Overload Operators                             */
/* ************************************************************************** */
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << "ShrubberyCreationForm assignment constructor called " << std::endl;
	if (this == &copy)
		return (*this);
	this->_target = copy.getTarget();
	return (*this);
}

/* std::ostream&	operator<<(std::ostream& stream, ShrubberyCreationForm& sh)
{
	stream << sh << " Target: " << sh.getTarget() << std::endl;
	return (stream);
} */
/* ************************************************************************** */
/*                             Public member functions                        */
/* ************************************************************************** */

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << "Bureaucrat " << executor.getName() << " is executing Form " << this->getName() << std::endl; 
	std::ofstream file;
	file.open((this->getTarget() + "_shrubbery").c_str(), std::ios::trunc);
	if (file.fail())
		std::cout << "Error When Trying to open " << this->getTarget() + "_shrubbery" << std::endl;
	file << ASCII_TREE;
	file.close();
}
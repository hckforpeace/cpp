#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
/*                             Constructors/Destructor                        */
/* ************************************************************************** */

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PredientialPardonForm destrucotr called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", PF_SIGNGRADE, PF_EXECGRADE), _target("default")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

/**
 * @brief PF_SIGNGRADE 25 PF_EXECGRADE 5
 */
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", PF_SIGNGRADE, PF_EXECGRADE), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm("PresidentialPardonForm", copy.getGradeSign(), copy.getGradeExec()), _target(copy.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = copy;
}


/* ************************************************************************** */
/*                             Overload Operators                             */
/* ************************************************************************** */

/* std::ostream& operator<<(std::ostream& stream, const PresidentialPardonForm &obj)
{
	stream << obj << " Target: " << obj.getTarget() << std::endl;
return (stream);
} */

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << "PresidentialPardonForm assignement constructor called" << std::endl;
	if (this == &copy)
		return (*this);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << "YOU HAVE BEEN PARDONED BY ZAPHOD BEEBLEBROX" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}
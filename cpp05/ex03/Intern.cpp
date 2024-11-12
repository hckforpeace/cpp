#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	(void)copy;
}

Intern& Intern::operator=(const Intern& copy)
{
	std::cout << "Assignment constructor called" << std::endl;
	(void)copy;
	return (*this);
}

AForm *Intern::makeShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}
AForm *Intern::makePresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}
AForm *Intern::makeRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makeForm(std::string form, std::string target) const
{
	std::string forms[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (*fun[3])(const std::string target) =
	{
		&makeShrubberyCreationForm,
		&makeRobotomyRequestForm,
		&makePresidentialPardonForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == form)
		{
			std::cout << "Intern creates " << forms[i] << std::endl;
			return (fun[i])(target);
		}
	}
	std::cout << "Form " << form << " was not found" << std::endl;
	return (NULL);
}
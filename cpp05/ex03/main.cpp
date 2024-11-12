#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
// Constructor Tests
int	main()
{
	Intern bob;
	// Robottomysation
	AForm* f = bob.makeForm("shrubbery creation", "people");
	Bureaucrat LOLO("lolo", 1);
	std::cout << std::string(50, '*') << std::endl;
	if (f)
	{
		LOLO.signForm(*f);
		LOLO.executeForm(*f);
		std::cout << std::string(50, '*') << std::endl;
	}
	delete f;
	return (0);
}

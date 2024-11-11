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
	LOLO.signForm(*f);
	LOLO.executeForm(*f);
	std::cout << std::string(50, '*') << std::endl;

	// Shruberry
/* 	AForm *s = new ShrubberyCreationForm("BOOBOO");
	Bureaucrat COCO("lolo", 26);
	std::cout << std::string(50, '*') << std::endl;
	COCO.signForm(*s);
	COCO.executeForm(*s);
	std::cout << std::string(50, '*') << std::endl; */

	//PresidentialPardon
/* 	AForm *p = new PresidentialPardonForm("BOOBOO");
	Bureaucrat POPO("lolo", 5);
	std::cout << std::string(50, '*') << std::endl;
	POPO.signForm(*p);
	POPO.executeForm(*p);
	std::cout << std::string(50, '*') << std::endl; */


	// delete r;
	// delete s;
	// delete p;
	return (0);
}

// Basic stuff
/* int main()
{
	Bureaucrat Pipo("Pierre", 46);
	std::cout << Pipo << std::endl;

	ShrubberyCreationForm sf("Kids");
	RobotomyRequestForm rf("Men");
	PresidentialPardonForm pf("Women");

	std::cout << std::string(50, '*') << std::endl;
	std::cout << sf << std::endl;
	std::cout << rf << std::endl;
	std::cout << pf << std::endl;

	PresidentialPardonForm cp1 = pf;
	RobotomyRequestForm cp2 = rf;
	ShrubberyCreationForm cp3 = sf;

	std::cout << cp3 << std::endl;
	std::cout << cp2 << std::endl;
	std::cout << cp1 << std::endl;

	std::cout << cp3.getTarget() << std::endl;
	std::cout << cp2.getTarget() << std::endl;
	std::cout << cp1.getTarget() << std::endl;
	
	std::cout << std::string(50, '*') << std::endl;
	return (0);
} */
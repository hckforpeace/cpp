#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	private:
		static AForm *makeShrubberyCreationForm(const std::string target);
		static AForm *makePresidentialPardonForm(const std::string target);
		static AForm *makeRobotomyRequestForm(const std::string target);
	public:
		Intern();
		Intern(const Intern &copy);
		Intern& operator=(const Intern &copy);
		AForm* makeForm(std::string Form, std::string target) const;
};

#endif
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#define PF_EXECGRADE 5
#define PF_SIGNGRADE 25

class PresidentialPardonForm: public AForm 
{
	private:
		std::string _target;
	public:
		~PresidentialPardonForm();
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &copy);

		std::string getTarget() const;

		void execute(Bureaucrat const & executor) const;

};

// std::ostream& operator<<(std::ostream& stream, const PresidentialPardonForm &obj);

#endif
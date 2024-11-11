#ifndef ROBOTOMYRERQUESTFORM_HPP
#define ROBOTOMYRERQUESTFORM_HPP

#include "AForm.hpp"
#define SIGNGRADE 72
#define EXECGRADE 45
#include <cstdlib>
class RobotomyRequestForm: public AForm 
{
	private:
		std::string _target;
	public:
		~RobotomyRequestForm();
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm &copy);

		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
};

// std::ostream& operator<<(std::ostream& stream, const RobotomyRequestForm &obj);

#endif
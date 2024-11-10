#include "Bureaucrat.hpp"

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& obj)
{
	stream << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (stream);
}

// Constructor Tests
int	main()
{
	// Exceptions on the form constructor
/* 	try
	{
		Form retirement("retirement", 180, 180);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form retirement("retirement", 0, 18);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	} */

	// Constructing
	Form retirement("retirement", 1, 1);
	Bureaucrat Wolf("Wolf", 1);

	// the form will be signed
	Wolf.signForm(retirement);
	// the form is already signed
	Wolf.signForm(retirement);

	// sign form will throw an exception
	std::cout << std::string(50, '*') << std::endl;
	Bureaucrat Walid("Loute", 12);
	Walid.signForm(retirement);

}
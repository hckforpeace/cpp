#include "Bureaucrat.hpp"

// Constructor Tests
int	main()
{
	std::cout << std::string(50, '*') << std::endl;
	// GradeTooHigh
	try
	{
		Bureaucrat alan("Alan", 0);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << " grade must be between 1 and 150" << std::endl;	
	}

	// GradeTooLow
	std::cout << std::endl << std::string(50, '*') << std::endl;
	try
	{
		Bureaucrat alan("alan", 151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << " grade must be between 1 and 150" << std::endl;	
	}

	// Good Grade
	std::cout << std::endl << std::string(50, '*') << std::endl;
	try
	{
		Bureaucrat alan("alan", 11);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << " grade must be between 1 and 150" << std::endl;	
	}
	std::cout << "outside the scope" << std::endl;

	return (0);
}

// Increment decrement tests
/* int main()
{
	// decrement throws an error
	std::cout << std::endl << std::string(50, '*') << std::endl;	
	Bureaucrat Pipo("Pierre", 150);
	try
	{
		Pipo.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << " grade must be between 1 and 150" << std::endl;	
		std::cout << Pipo << std::endl;
	}

	try
	{
		Pipo.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << " grade must be between 1 and 150" << std::endl;	
	}
	std::cout << Pipo << std::endl;

	// Increment throws an error
	std::cout << std::endl << std::string(50, '*') << std::endl;
	Bureaucrat Alan("Pierre", 1);
	try
	{
		Alan.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << " grade must be between 1 and 150" << std::endl;	
		std::cout << Alan << std::endl;
	}

	try
	{
		Alan.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << " grade must be between 1 and 150" << std::endl;	
	}
	std::cout << Alan << std::endl;
} */

// Canonical tests
/* int	main()
{
	Bureaucrat Pablo("Pablo", 1);
	// Bureaucrat Pierre("Pierre", 1);

	// Pierre = Pablo;
	Bureaucrat Pierre = Pablo;

	Bureaucrat Pipo(Pablo);
	

	std::cout << Pablo << std::endl;
	std::cout << Pierre << std::endl;
	std::cout << Pipo << std::endl;
	
	
	return 0;
} */
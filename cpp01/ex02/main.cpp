#include <iostream>

int	main()
{
	std::string	brain = "HI THIS IS BRAIN";

	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "variable brain adress: " << &brain << std::endl;
	std::cout << "address in stringPTR: " << stringPTR << std::endl;
	std::cout << "adress in string PTR: " << &stringREF << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "value of brain: " << brain << std::endl;
	std::cout << "pointed value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "pointed value of stringREF: " << stringREF << std::endl;

	return (0);
}

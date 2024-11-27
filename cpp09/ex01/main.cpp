#include "RPN.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	(void) argv;
	(void) argc;
	std::string input = "1 2 3 4 5 6 7 9";
	// std::cout << input.substr(0, input.find_first_of(' ', 2)) << std::endl;
	try
	{
		RPN::parse_input(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
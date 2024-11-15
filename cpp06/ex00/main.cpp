#include <iostream>
#include "ScalarConverter.hpp"
bool	parse_string(std::string data);

int	main(int argc, char** argv)
{
	if (argc == 2)
	{
		std::string input = argv[1];
		ScalarConverter::convert(input);
	}
	else
		std::cout << "./convert integer, float or double" << std::endl;
	return (0);
}
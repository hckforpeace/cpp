#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char** argv)
{
	// if (argc != 2)
	// 	std::cerr << "Error" << std::endl;
	// else
	// {
		std::string input[argc - 1];
		for (int i = 1; i < argc; i++)
			input[i - 1] = argv[i];
		PmergeMe obj(input, argc - 1);
	// }
	return (0);
}
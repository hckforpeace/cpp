#include "PmergeMe.hpp"
#include <iostream>


int	main(int argc, char** argv)
{
	if (argc > 1)
	{
		std::string input[argc - 1];
		for (int i = 1; i < argc; i++)
			input[i - 1] = argv[i];
		try
		{
			PmergeMe obj(input, argc - 1);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		std::cerr << "./PmergeMe [int1] [int2] [int3] ..." << std::endl;
	return (0);
}

#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char** argv)
{
	std::string input[argc - 1];
	for (int i = 1; i < argc; i++)
		input[i - 1] = argv[i];
	try
	{
		PmergeMe obj(input, argc - 1);
		// obj.display();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
/* 	std::vector<int> s = {1, 2, 3, 4};
	std::vector<int> t = {5,6,7,8};
	std::vector<int> copy(t.begin(), t.end());
	copy.insert(copy.begin() + copy.size(), t.begin(), t.end());

	for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
		std::cout << *it << std::endl;
	return (0); */
}
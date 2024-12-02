#include "PmergeMe.hpp"
#include <iostream>

int get_max(std::vector<int>& left, std::vector<int>& right);

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
	// std::vector<int> v1 = {23};
	// std::vector<int> v2 = {1222};
	// std::cout << get_max(v1, v2) << std::endl;
	// std::vector<int> s = {1, 2, 3, 4};
	// std::vector<int> t = {5,6,7,8};
	// std::vector<int> copy(t.begin(), t.end());
	// copy.insert(copy.begin() + copy.size(), t.begin(), t.end());

	// for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
	// 	std::cout << *it << std::endl;
	// return (0);
}

/* int	main()
{
	std::vector<int> s = {2, 11, 0, 17, 6, 15, 8, 16, 3, 10, 1, 21, 9, 18, 14, 19, 5, 12, 4, 20, 7, 13};
	std::cout << PmergeMe::is_sorted(s, 8, 4);
	return (0);
} */
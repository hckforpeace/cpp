#include <iostream>
#include <vector>
#include "easyfind.hpp"

/* int	main()
{
	std::vector<int> tab = {1, 2, 3, 4, 4, 5, 5, 6, 4, 3, 76, 345};
	try
	{
		std::vector<int>::iterator i = easyfind(tab, 2);
		for(i; i != tab.end(); i++)
			std::cout << *i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
} */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> tab = {1, 2, 3, 4, 4, 5, 5, 6, 4, 3, 76, 345};

	try
	{
		std::vector<int>::iterator it = easyfind(tab, 3);
		for (; it < tab.end(); it++)
			std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
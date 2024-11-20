#include <iostream>
#include <vector>
#include "MutantStack.hpp"

int main()
{
/* 	std::vector<int> tab = {1, 2, 3};
	for (std::vector<int>::const_iterator it = tab.cbegin() ; it != tab.cend() ; it++)
	{
		std::cout << *it << std::endl;
		*it = 2;
	}	
return (0); */

	MutantStack<int> ms;
	ms.push(2);
	ms.push(3);
	ms.push(4);
	ms.push(5);
	ms.push(6);
	ms.push(7);

	for (MutantStack<int>::const_iterator it = ms.begin(); it != ms.end() ; it++)
	{
		std::cout << *it << std::endl;
	}
 
	return (0);
}
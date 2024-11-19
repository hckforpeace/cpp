#include <iostream>
#include <vector>

int main()
{
	std::vector<int> tab = {1, 2, 3};
	for (std::vector<int>::const_iterator it = tab.cbegin() ; it != tab.cend() ; it++)
	{
		std::cout << *it << std::endl;
		*it = 2;
	}	
return (0);
}
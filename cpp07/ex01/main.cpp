#include "iter.hpp"
#include <iostream>

void	increment(int &i)
{
	i++;
}

int	main()
{
	int tab[20];

	for (int i = 0; i < 20; i++)
		tab[i] = i;

	for (int i = 0; i < 10; i++)
		std::cout << i << ": " << tab[i] << std::endl;

	iter(tab, 20, increment);

	std::cout << std::string(10, '*') << std::endl;

	for (int i = 0; i < 10; i++)
		std::cout << i << ": " << tab[i] << std::endl;
	
}
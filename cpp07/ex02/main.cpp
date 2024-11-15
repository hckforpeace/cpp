#include <iostream>

int	main()
{
	int *a = new int[2];
	for (int i = 0; i < 2; i++)
		std::cout << a[i] << std::endl;
	return (0);
}
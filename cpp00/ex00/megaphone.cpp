#include <iostream>
#include <cstring>

int	main(int argc, char **argv)
{
	int	i;
	int j;

	if (argc > 1)
	{
		for(i=1; i < argc; i++)
		{
			for (j= 0; j < strlen(argv[i]); j++)
			{
				if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
					std::cout << (char)(argv[i][j] - 32);
				else
					std::cout << argv[i][j];
			}
			if (i + 1 < argc)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	return (0);
}

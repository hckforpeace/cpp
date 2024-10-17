#include <iostream>
#include "FileReplace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "./replace filename str1 str2";
		return (0);
	}
	FileReplace myfile(argv[1], argv[2], argv[3]);
	myfile.replace();
	return (0);
}
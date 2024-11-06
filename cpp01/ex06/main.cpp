#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "./HardFilter 	\"complaining level\"" << std::endl;
		std::cout << "Levels: WARNING, ERROR, INFO, DEBUG, ERROR" << std::endl;
	}
	else
	{
		std::string level = argv[1];
		Harl harl = Harl();
		harl.filterComplain(level);
	}
	return (0);
}
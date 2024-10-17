#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "./HardFilter 	\"complaining level\"" << std::endl;
	else
	{
		std::string level = argv[1];
		Harl harl = Harl();
		harl.filterComplain(level);
	}
	return (0);
}
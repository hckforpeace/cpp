#include "Zombie.hpp"

int	main()
{
	std::string name;

	std::cout << "creationg a zombie on the stack" << std::endl;
	std::cin >> name;

	randomChump(name);
	std::cout << std::endl << std::string(20, '*') << std::endl << "out of random chump !" << std::endl << std::string(20, '*')  << std::endl;

	std::cout << "creationg a zombie on the heap (new)" << std::endl;
	std::cin >> name;

	Zombie *my_zombie = newZombie(name);
	std::cout << std::endl << std::string(20, '*') << std::endl << "out of newZombie !" << std::endl << std::string(20, '*')  << std::endl;

	delete my_zombie;
	return (0);
}
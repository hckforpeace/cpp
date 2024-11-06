#include "Zombie.hpp"

int	main()
{
	std::string name;

	std::cout << "Input a Zombie name: ";
	std::cin >> name;
	std::cout << std::endl << "creating a zombie " << name <<" on the stack" << std::endl;

	randomChump(name);
	std::cout << std::endl << std::string(20, '*') << std::endl << "out of random chump !" << std::endl << std::string(20, '*')  << std::endl;

	std::cout << std::endl << "Input a Zombie name: ";
	std::cin >> name;
	std::cout << "creating a zombie on the heap (new)" << std::endl;

	Zombie *my_zombie = newZombie(name);
	std::cout << std::endl << std::string(20, '*') << std::endl << "out of newZombie !" << std::endl << std::string(20, '*')  << std::endl;

	delete my_zombie;
	return (0);
}
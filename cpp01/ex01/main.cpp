#include "Zombie.hpp"

int	main()
{
	Zombie *horde = zombieHorde(50, "Pablo");

	for(int i = 0; i < 50; i++)
		horde[i].announce();
	
	delete[] horde;
	return (0);
}
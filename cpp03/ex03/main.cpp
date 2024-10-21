#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
// overload the << operator
/* std::ostream& operator<<(std::ostream& stream, const ClapTrap& obj)
{
	std::cout << std::string(10, '*') << std::endl;
	stream << "_name: " << obj._name << ", _hp: " << obj.getHitPoints() << ", _ep: " << obj.getEnergyPoints() << ", Damage: " << obj.getAttackDamage() << std::endl;
	std::cout << std::string(10, '*') << std::endl;
	return stream;
} */

int	main()
{
	// ScavTrap scav("Yahya");

	// std::cout << scav;
	// scav.attack("Mahmoud");
	// scav.takeDamage(20);
	// std::cout << scav;
	// scav.beRepaired(3);
	// std::cout << scav;
	// scav.attack("Mahmoud");
	// scav.attack("Mahmoud");
	// scav.attack("Mahmoud");
	// scav.attack("Mahmoud");
	// scav.attack("Mahmoud");
	// scav.attack("Mahmoud");
	// std::cout << scav;
	// scav.beRepaired(10);
	// std::cout << scav;
	// scav.guardGate();
	DiamondTrap Rihanna("Rihanna");

	Rihanna.display();

	Rihanna.whoAmI();
	return (0);
}
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
// overload the << operator
std::ostream& operator<<(std::ostream& stream, const ClapTrap& obj)
{
	std::cout << std::endl << std::string(10, '*') << std::endl;
	stream << "_name: " << obj.get_name() << ", _hp: " << obj.getHitPoints() << ", _ep: " << obj.getEnergyPoints() << ", Damage: " << obj.getAttackDamage() << std::endl;
	std::cout << std::string(10, '*') << std::endl;
	return stream;
}

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
	ClapTrap	clap("clap");
	ScavTrap	scav("scav");
	FragTrap	frag("frag");
	DiamondTrap Rihanna("Rihanna");

	Rihanna.display();
	scav.guardGate();
	frag.highFivesGuys();
	
	std::cout << Rihanna << std::endl;
	std::cout << scav << std::endl;
	std::cout << frag << std::endl;
	std::cout << clap << std::endl;

	Rihanna.whoAmI();
	return (0);
}
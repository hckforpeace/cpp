#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
// overload the << operator
std::ostream& operator<<(std::ostream& stream, const ClapTrap& obj)
{
	std::cout << std::string(10, '*') << std::endl;
	stream << "_name: " << obj.get_name() << ", _hp: " << obj.getHitPoints() << ", _ep: " << obj.getEnergyPoints() << ", Damage: " << obj.getAttackDamage() << std::endl;
	std::cout << std::string(10, '*') << std::endl;
	return stream;
}

int	main()
{
	// scav.takeDamage(20);
	ScavTrap scav("Yahya");
	FragTrap frag("bitch");

	std::cout << scav << std::endl;
	std::cout << frag << std::endl;

	frag.highFivesGuys();
	scav.guardGate();
/* 	scav.attack("Mahmoud");
	scav.takeDamage(20);
	std::cout << scav;
	scav.beRepaired(3);
	std::cout << scav;
	scav.attack("Mahmoud");
	scav.attack("Mahmoud");
	scav.attack("Mahmoud");
	scav.attack("Mahmoud");
	scav.attack("Mahmoud");
	scav.attack("Mahmoud");
	std::cout << scav;
	scav.beRepaired(10);
	std::cout << scav;
	scav.guardGate(); */
	return (0);
}
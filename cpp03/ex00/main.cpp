#include "ClapTrap.hpp"

std::ostream& operator<<(std::ostream& stream, const ClapTrap& obj)
{
	std::cout << std::string(10, '*') << std::endl;
	stream << "_name: " << obj.get_name() << ", _hp: " << obj.getHitPoints() << ", _ep: " << obj.getEnergyPoints() << ", Damage: " << obj.getAttackDamage() << std::endl;
	std::cout << std::string(10, '*') << std::endl;
	return stream;
}

int	main()
{
	ClapTrap clp1("Yahya");

	std::cout << clp1;
	clp1.attack("Mahmoud");
	clp1.takeDamage(20);
	std::cout << clp1;
	clp1.beRepaired(3);
	std::cout << clp1;
	clp1.attack("Mahmoud");
	clp1.attack("Mahmoud");
	clp1.attack("Mahmoud");
	clp1.attack("Mahmoud");
	clp1.attack("Mahmoud");
	clp1.attack("Mahmoud");
	std::cout << clp1;
	clp1.beRepaired(10);
	std::cout << clp1;
	return (0);
}
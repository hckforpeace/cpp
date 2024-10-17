#include "HumanA.hpp"

HumanA::~HumanA()
{
	std::cout << std::endl << "intance " << this->name << " of HumanA was destroyed" << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon)
{
}

void	HumanA::attack()
{
	std::cout << this->name << "attacks with their weapon " << this->weapon.getType() << std::endl;
}
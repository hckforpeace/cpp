#include "HumanB.hpp"

HumanB::~HumanB()
{
	std::cout << std::endl << "intance " << this->name << " of HumanB was destroyed" << std::endl;
}


HumanB::HumanB(std::string name)
{
	this->name = name;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack()
{
	std::cout << this->name << "attacks with their weapon " << (*this->weapon).getType() << std::endl;
}

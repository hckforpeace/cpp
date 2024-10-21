#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string _name)
    : ClapTrap(_name + "_clap__name"), _name(_name)
{
    _hp = FragTrap::_hp;
    _ep = ScavTrap::_ep;
    Damage = FragTrap::Damage;

    std::cout << "DiamondTrap Constructor called for " << _name << std::endl;
}

void DiamondTrap::attack(const std::string target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)\
{
	std::cout << "_name: " << this->_name << ", ClapTrap _name: " << this->ClapTrap::_name << std::endl;
}

void	 DiamondTrap::display()
{
	std::cout << "Damage: " << Damage << ", _hp: " << _hp << ", _ep: " << _ep << std::endl;
}
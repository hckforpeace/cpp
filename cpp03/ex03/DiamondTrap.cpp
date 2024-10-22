#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string _name)
    : ClapTrap(_name + "_clap_name"), _name(_name + "_clap__name")
{
	this->_name = _name;
    this->_hp = FragTrap::_hp;
    this->_ep = ScavTrap::_ep;
    this->Damage = FragTrap::Damage;

    std::cout << "DiamondTrap Constructor called for " << _name << std::endl;
}

void DiamondTrap::attack(const std::string target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "_name: " << this->_name << ", ClapTrap _name: " << this->ClapTrap::_name << std::endl;
}

void	 DiamondTrap::display()
{
	std::cout << "Damage: " << this->Damage << ", _hp: " << this->_hp << ", _ep: " << this->_ep << std::endl;
}
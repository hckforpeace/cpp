#include "DiamondTrap.hpp"

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructoir was called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj)
{
    operator=(obj);
}

DiamondTrap::DiamondTrap(void): ClapTrap("_clap_name"), _name("")
{
    this->_hp = FragTrap::_hp;
    this->_ep = 50;
    this->Damage = FragTrap::Damage;

    std::cout << "DiamondTrap Constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name)
    : ClapTrap(_name + "_clap_name"), _name(_name)
{
    this->_hp = FragTrap::_hp;
    this->_ep = 50;
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

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
    this->_ep = obj._ep;
    this->Damage = obj.Damage;
    this->_hp = obj._hp;
    this->_name = obj._name;
    return *this;
}
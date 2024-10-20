#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
    this->hitPoints = this->FragTrap::hitPoints;
    this->energyPoints = this->ScavTrap::energyPoints;
    this->attackDamage = this->FragTrap::attackDamage;

    std::cout << "DiamondTrap Constructor called for " << name << std::endl;
}

void DiamondTrap::attack(const std::string target)
{
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)\
{
	std::cout << "name: " << this->name << ", ClapTrap name: " << this->ClapTrap::name << std::endl;
}

void	 DiamondTrap::display()
{
	std::cout << "attackdamage: " << this->attackDamage << ", hitpoints: " << this->hitPoints << ", energyPoints: " << this->energyPoints << std::endl;
}
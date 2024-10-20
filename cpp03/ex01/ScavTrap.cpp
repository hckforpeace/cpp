#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setName(name);
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(void)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	this->setName("John");
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is in now in Gate keeper mode" << std::endl;
}
#include "ScavTrap.hpp"

//Constructors

ScavTrap::ScavTrap(ScavTrap const &obj)
{
	operator=(obj);
}

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

// Methods

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is in now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() > 0 && this->getEnergyPoints() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

//Operator
ScavTrap& ScavTrap::operator=(ScavTrap const &obj)
{
	this->setName(obj.getName());
	this->setAttackDamage(obj.getAttackDamage());
	this->setEnergyPoints(obj.getEnergyPoints());
	this->setHitPoints(obj.getHitPoints());
	return *this;
}

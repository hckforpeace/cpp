#include "ScavTrap.hpp"

//Constructors

ScavTrap::ScavTrap(ScavTrap const &obj): ClapTrap(obj)
{
	operator=(obj);
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->name = name;
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(void): ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->name = "John";
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

// Methods

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " is in now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints = this->energyPoints - 1;
	}
}

//Operator
ScavTrap& ScavTrap::operator=(ScavTrap const &obj)
{
	this->name = obj.name;
	this->attackDamage = obj.attackDamage;
	this->energyPoints = obj.energyPoints;
	this->hitPoints = obj.hitPoints;
	return *this;
}

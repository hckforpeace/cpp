#include "ClapTrap.hpp"

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(void):name("John")
{
	std::cout << "ClapTrap Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):name(name)
{
	std::cout << "Constructor Called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " amount of damage!" << std::endl;
	if (this->hitPoints > 0)
	{
		this->hitPoints -= amount;
		if (this->hitPoints < 0)
			this->hitPoints = 0;
	}
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0)
	{
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " repairs it self by " << amount << " points!" << std::endl;
		this->hitPoints += amount;
	}
}

//getters

unsigned int	ClapTrap::getHitPoints(void) const
{
	return this->hitPoints;
}
unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return this->energyPoints;
}
unsigned int	ClapTrap::getAttackDamage(void) const
{
	return this->attackDamage;
}

std::string		ClapTrap::getName(void) const
{
	return this->name;
}

void			ClapTrap::setName(std::string name)
{
	this->name = name;
}

void			ClapTrap::setHitPoints(int points)
{
	this->hitPoints = points;
}

void			ClapTrap::setEnergyPoints(int points)
{
	this->energyPoints = points;
}

void			ClapTrap::setAttackDamage(int damage)
{
	this->attackDamage = damage;
}
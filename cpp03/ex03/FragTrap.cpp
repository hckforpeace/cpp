#include "FragTrap.hpp"

FragTrap::FragTrap(FragTrap const &obj): ClapTrap(obj)
{
	operator=(obj);
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	this->name = name;
	std::cout << "FragTrap Constructor Called" << std::endl;
}

FragTrap::FragTrap(void): ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	this->name = "John";
	std::cout << "FragTrap Constructor Called" << std::endl;
}

//Destructor
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor Called" << std::endl;
}

//Destructor
void FragTrap::highFivesGuys(void)
{
	std::cout << "Hello I am ScravTrap" << this->name << ", I am positive and request a High Five" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &obj)
{
	this->name = obj.name;
	this->attackDamage = obj.attackDamage;
	this->energyPoints = obj.energyPoints;
	this->hitPoints = obj.hitPoints;
	return *this;
}
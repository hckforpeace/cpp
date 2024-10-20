#include "FragTrap.hpp"

FragTrap::FragTrap(FragTrap const &obj)
{
	operator=(obj);
}

FragTrap::FragTrap(void)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setName("John");
	std::cout << "FragTrap Constructor Called" << std::endl;
}
FragTrap::FragTrap(std::string name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	this->setName(name);
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
	std::cout << "Hello I am ScravTrap" << this->getName() << ", I am positive and request a High Five" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &obj)
{
	this->setName(obj.getName());
	this->setAttackDamage(obj.getAttackDamage());
	this->setEnergyPoints(obj.getEnergyPoints());
	this->setHitPoints(obj.getHitPoints());
	return *this;
}
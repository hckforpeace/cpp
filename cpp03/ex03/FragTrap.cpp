#include "FragTrap.hpp"

FragTrap::FragTrap(FragTrap const &obj): ClapTrap(obj)
{
	operator=(obj);
}

FragTrap::FragTrap(std::string _name): ClapTrap(_name)
{
	this->_hp = 100;
	this->_ep = 100;
	this->Damage = 30;
	this->_name = _name;
	std::cout << "FragTrap Constructor Called" << std::endl;
}

FragTrap::FragTrap(void): ClapTrap()
{
	this->_hp = 100;
	this->_ep = 100;
	this->Damage = 30;
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
	std::cout << "Hello I am ScravTrap" << this->_name << ", I am positive and request a High Five" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &obj)
{
	this->_name = obj._name;
	this->Damage = obj.Damage;
	this->_ep = obj._ep;
	this->_hp = obj._hp;
	return *this;
}

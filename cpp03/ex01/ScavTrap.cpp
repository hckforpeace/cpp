#include "ScavTrap.hpp"

//Constructors

ScavTrap::ScavTrap(ScavTrap const &obj)
{
	operator=(obj);
}

ScavTrap::ScavTrap(std::string _name)
{
	this->_name = _name;
	this->_hp = 100;
	this->_ep = 50;
	this->Damage = 20;
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(void)
{
	this->_hp = 100;
	this->_ep = 50;
	this->Damage = 20;
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

//Method
void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->get_name() << " is in now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() > 0 && this->getEnergyPoints() > 0)
	{
		std::cout << "ScavTrap " << this->get_name() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->_ep -= 1;
	}
}

//Operator
ScavTrap& ScavTrap::operator=(ScavTrap const &obj)
{
	this->_name = obj._name;
	this->Damage = obj.Damage;
	this->_ep = obj._ep;
	this->_hp = obj._hp;
	return *this;
}

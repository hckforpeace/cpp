#include "ScavTrap.hpp"

//Constructors

ScavTrap::ScavTrap(ScavTrap const &obj): ClapTrap(obj)
{
	std::cout << "ScavTrap copy Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string _name): ClapTrap(_name)
{
	this->_hp = 100;
	this->_ep = 50;
	this->Damage = 20;
	this->_name = _name;
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(void): ClapTrap()
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

// Methods

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is in now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hp > 0 && this->_ep > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->Damage << " points of damage!" << std::endl;
		this->_ep = this->_ep - 1;
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

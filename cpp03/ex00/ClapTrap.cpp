#include "ClapTrap.hpp"

// Constructors

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(void):_hp(10), _ep(10), Damage(0)
{
	std::cout << "Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name):_hp(10), _ep(10), Damage(0)
{
	std::cout << "Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &clp)
{
	operator=(clp);
}

// Methods

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hp > 0 && this->_ep > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->Damage << " points of damage!" << std::endl;
		this->_ep--;
	}
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " amount of damage!" << std::endl;
	if (this->_hp > 0)
	{
		this->_hp -= amount;
		if (this->_hp < 0)
			this->_hp = 0;
	}
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_ep > 0)
	{
		this->_ep--;
		std::cout << "ClapTrap " << this->_name << " repairs it self by " << amount << " points!" << std::endl;
		this->_hp += amount;
	}
}

//Getters

unsigned int	ClapTrap::getHitPoints(void) const
{
	return this->_hp;
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return this->_ep;
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return this->Damage;
}

std::string		ClapTrap::get_name(void) const
{
	return this->_name;
}

// Operator

ClapTrap&		ClapTrap::operator=(ClapTrap const &clp)
{
	this->_name = clp._name;
	this->Damage = clp.Damage;
	this->_ep = clp._ep;
	this->_hp = clp._hp;
	return *this;
}
#include "ClapTrap.hpp"

//Constructors
ClapTrap::ClapTrap(ClapTrap const &clp)
{
	operator=(clp);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(void):_name("Default"), _hp(10), _ep(10), Damage(10)
{
	std::cout << "ClapTrap Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name):_name(_name), _hp(10), _ep(10), Damage(10)
{
	std::cout << "Constructor Called" << std::endl;
}

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

//getters

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
/*
void			ClapTrap::set_name(std::string _name)
{
	this->_name = _name;
}

void			ClapTrap::setHitPoints(int points)
{
	this->_hp = points;
}

void			ClapTrap::setEnergyPoints(int points)
{
	this->_ep = points;
}

void			ClapTrap::setAttackDamage(int damage)
{
	this->Damage = damage;
} */

//operator
ClapTrap&		ClapTrap::operator=(ClapTrap const &clp)
{
	this->_name = clp._name;
	this->Damage = clp.Damage;
	this->_ep = clp._ep;
	this->_hp = clp._hp;
	return *this;
}
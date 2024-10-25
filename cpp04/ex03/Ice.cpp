#include "Ice.hpp"

Ice::Ice():AMateria("ice")
{
	std::cout << "Ice Constructor called" << std::endl;
}

Ice::Ice(const Ice &obj):AMateria("ice")
{
	std::cout << "Ice copy Constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &obj)
{
	this->type = type;
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria *clone = new Ice();
	return clone;
}
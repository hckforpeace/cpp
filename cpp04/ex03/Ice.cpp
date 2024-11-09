#include "Ice.hpp"

Ice::Ice():AMateria("ice")
{
	std::cout << "Ice Constructor called" << std::endl;
}

Ice::Ice(const Ice &copy):AMateria("ice")
{
	std::cout << "Ice copy Constructor called" << std::endl;
	*this = copy;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Ice Assignement Called" << std::endl;
	this->_type = copy.getType();
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria *clone = new Ice();
	return clone;
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{
	std::cout << "Cure Constructor called" << std::endl;
}

Cure::Cure(const Cure &copy):AMateria("cure")
{
	std::cout << "Cure copy Constructor called" << std::endl;
	*this = copy;
}

Cure::~Cure()
{
	std::cout << "Cure Destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Cure assignement Called" << std::endl;
	this->_type = copy.getType();
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria *clone = new Cure();
	return clone;
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
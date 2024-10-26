#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{
	std::cout << "Cure Constructor called" << std::endl;
}

Cure::Cure(const Cure &obj):AMateria("cure")
{
	std::cout << "Cure copy Constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure Destructor called" << std::endl;
}

Cure& Cure::operator=(const Cure &obj)
{
	this->type = type;
	return (*this);
}

AMateria* Cure::clone() const
{
	AMateria *clone = new Cure();
	return clone;
}
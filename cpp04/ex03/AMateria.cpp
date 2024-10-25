#include "AMateria.hpp"

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(std::string const & type):type(type)
{
	std::cout << "AMateria Constructor Called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->type;
}

/* void AMateria::use(ICharacter& target)
{

} */

AMateria::AMateria(AMateria const & obj)
{
	std::cout << "AMateria copy Constructor Called" << std::endl;
	operator=(obj);
}

AMateria & AMateria::operator=(AMateria const & obj)
{
	this->type = obj.getType();
	return *this;
}
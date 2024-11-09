#include "AMateria.hpp"

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(std::string const & type):_type(type)
{
	std::cout << "AMateria Constructor Called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

AMateria::AMateria(AMateria const & copy)
{
	std::cout << "AMateria copy Constructor Called" << std::endl;
	*this = copy;
}

AMateria & AMateria::operator=(AMateria const & copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "AMateria assignement operator called" << std::endl;
	this->_type = copy.getType();
	return *this;
}

void AMateria::use(ICharacter& target)
{
	if (this->_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

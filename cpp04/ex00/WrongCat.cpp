#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Constructor Called" << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor Called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Sound of a WrongCat Miaou..." << std::endl;
}
WrongCat::WrongCat(const WrongCat &copy):WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called" << std::endl;
	*this = copy;
}
WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "WrongCat destructor called" << std::endl;
	this->type = copy.getType();
	return (*this);
}

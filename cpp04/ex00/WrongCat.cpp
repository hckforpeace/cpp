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
WrongCat::WrongCat(const WrongCat &obj):WrongAnimal("WrongCat")
{
	operator=(obj);
}
WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	this->type = obj.getType();
	return (*this);
}

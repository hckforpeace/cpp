#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("Unknown")
{
	std::cout << "WrongAnimal Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor Called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string type):type(type)
{
	std::cout << "WrongAnimal Constructor Called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Sound of a WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "Animal constructor called" << std::endl;
	operator=(copy);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Animal constructor called" << std::endl;
	this->type = copy.getType();
	return (*this);
}

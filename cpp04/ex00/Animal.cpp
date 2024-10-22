#include "Animal.hpp"

Animal::Animal(void):type("Unknown")
{
	std::cout << "Animal constructor called !" << std::endl;
}

Animal::Animal(std::string type):type(type)
{
	std::cout << "Animal constructor called !" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called !" << std::endl;
}

Animal::Animal(const Animal &obj)
{
	operator=(obj);
}

Animal &Animal::operator=(const Animal& obj)
{
	this->type = obj.type;
	return *this;
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound(void) const
{

}

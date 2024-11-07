/* #include "Animal.hpp"

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
	std::cout << "Animal Sound";
}
 */

#include "Animal.hpp"

Animal::Animal(void):_type("Unknown")
{
	std::cout << "Animal constructor called !" << std::endl;
}

Animal::Animal(std::string type):_type(type)
{
	std::cout << "Animal constructor called !" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called !" << std::endl;
}


std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound(void) const
{
	std::cout << "Animal Sound..." << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called !" << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal& copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Animal Assignement constructor called" << std::endl;
	this->_type = copy._type;
	return *this;
}
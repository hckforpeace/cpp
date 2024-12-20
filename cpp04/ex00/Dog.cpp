#include "Dog.hpp"

void Dog::makeSound(void) const
{
	std::cout << "Wouaf..." << std::endl;
}

Dog::Dog(void):Animal("Dog")
{
	std::cout << "Dog Constructor Called" << std::endl;	
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;	
}

Dog::Dog(const Dog &copy): Animal("Dog")
{
	std::cout << "Dog copy Constructor Called" << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Dog Assignement constructor called" << std::endl;
	this->_type = copy.getType();
	return (*this);
}
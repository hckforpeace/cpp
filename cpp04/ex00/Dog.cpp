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

Dog::Dog(const Dog &obj)
{
	operator=(obj);
}

Dog& Dog::operator=(const Dog &obj)
{
	this->type = obj.type;
	return (*this);
}
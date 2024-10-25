#include "Dog.hpp"

void Dog::makeSound(void) const
{
	std::cout << "Wouaf..." << std::endl;
}

Dog::Dog(void): Animal("Dog")
{
	this->brain = new Brain();
	std::cout << "Dog Constructor Called" << std::endl;	
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Destructor Called" << std::endl;	
}

Dog::Dog(const Dog &obj): Animal("Dog")
{
	std::cout << "Dog copy constructor" << std::endl;
	operator=(obj);
}

Dog& Dog::operator=(const Dog &obj)
{
	this->type = obj.type;
	this->brain = new Brain(*obj.brain);
	return (*this);
}
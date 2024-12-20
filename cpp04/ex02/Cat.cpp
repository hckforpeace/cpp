#include "Cat.hpp"

void Cat::makeSound(void) const
{
	std::cout << "Miaouuuu..." << std::endl;
}

Cat::Cat(void):Animal("Cat"), brain(new Brain())
{
	std::cout << "Cat Constructor Called" << std::endl;	
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat &copy): Animal("Cat")
{
	std::cout << "Cat Constructor Called" << std::endl;	
	*this = copy;
}
Cat& Cat::operator=(const Cat &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Cat Assignement constructor called" << std::endl;
	if (this->brain)
		delete this->brain;
	this->_type = copy.getType();
	this->brain = new Brain(*copy.brain);
	return (*this);
}
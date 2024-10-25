#include "Cat.hpp"

void Cat::makeSound(void) const
{
	std::cout << "Miaouuuu..." << std::endl;
}

Cat::Cat(void):Animal("Cat")
{
	this->brain = new Brain();
	std::cout << "Cat Constructor Called" << std::endl;	
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat Destructor Called" << std::endl;	
}

Cat::Cat(const Cat &obj): Animal("Cat")
{
	std::cout << "Cat copy constructor" << std::endl;
	operator=(obj);
}

Cat& Cat::operator=(const Cat &obj)
{
	this->type = obj.type;
	this->brain = new Brain(*obj.brain);
	return (*this);
}
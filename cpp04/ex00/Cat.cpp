#include "Cat.hpp"

void Cat::makeSound(void) const
{
	std::cout << "Miaouuuu..." << std::endl;
}

Cat::Cat(void):Animal("Cat")
{
	std::cout << "Cat Constructor Called" << std::endl;	
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;	
}
#include "Brain.hpp"

//TODO

Brain::Brain(void)
{
	std::cout << "Brain Constructor Called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "I Want To Play";
}


Brain::~Brain()
{
	std::cout << "Brain is out !" << std::endl;
}

Brain::Brain(const Brain& obj)
{
	operator=(obj);
}

Brain&	Brain::operator=(const Brain &obj)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	return (*this);
}
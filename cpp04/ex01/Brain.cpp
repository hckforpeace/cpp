#include "Brain.hpp"

//TODO
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
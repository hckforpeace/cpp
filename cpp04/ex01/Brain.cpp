#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain is being formed (Constructor)" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "I Want To Play";
}

Brain::~Brain()
{
	std::cout << "Brain is out ! (Destructor)" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain is being formed (copy Constructor)" << std::endl;
	*this = copy;
}

Brain&	Brain::operator=(const Brain &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << "Brain Assignement operator is Called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}
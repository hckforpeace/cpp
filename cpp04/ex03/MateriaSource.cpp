#include "MateriaSource.hpp"

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materials[i])
			delete this->materials[i];
	}
}

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->materials[i] = NULL;
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->materials[i])
		{
			this->materials[i] = m;
			return ;
		}
	}
	std::cout << "Already learned maximum amount of materia" << std::endl;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materials[i] && !this->materials[i]->getType().compare(type))
			return this->materials[i]->clone();
	}
	std::cout << "Type not found" << std::endl;
	return (0);
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	std::cout << "MateriaSource Copy Constructor Called" << std::endl;
	*this = copy;
}


MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
{
	if (this == &copy)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (copy.materials[i])
			this->materials[i] = copy.materials[i]->clone();
		else
			this->materials[i] = NULL;
	}
	return (*this);
}

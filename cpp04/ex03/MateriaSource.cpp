#include "MateriaSource.hpp"

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->matrials[i])
			delete this->matrials[i];
	}
}

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->matrials[i] = NULL;
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->matrials[i])
		{
			this->matrials[i] = m;
			return ;
		}
	}
	std::cout << "Already learned maximum amount of materia" << std::endl;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->matrials[i] && !this->matrials[i]->getType().compare(type))
			return this->matrials[i]->clone();
	}
	std::cout << "Type not found" << std::endl;
	return (0);
}

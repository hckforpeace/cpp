#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <string>

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *matrials[4];
	public:
		MateriaSource();
		virtual ~MateriaSource();
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);

};

#endif
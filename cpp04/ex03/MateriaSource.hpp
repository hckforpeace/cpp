#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <string>

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *materials[4];
	public:
		MateriaSource();
		virtual ~MateriaSource();
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
		MateriaSource(const MateriaSource& copy);
		MateriaSource& operator=(const MateriaSource& copy);

};

#endif
#ifndef ICE_HPP
#define ICE_HPP

// class AMateria;
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice &obj);
		Ice &operator=(const Ice& obj);
		AMateria* clone() const;
};

#endif
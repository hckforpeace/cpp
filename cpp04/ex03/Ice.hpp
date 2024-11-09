#ifndef ICE_HPP
#define ICE_HPP

// class AMateria;
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		// Canonical Form
		Ice();
		~Ice();
		Ice(const Ice &copy);
		Ice &operator=(const Ice& copy);
		AMateria* clone() const;

		//Methods
		void use(ICharacter& target);

};

#endif
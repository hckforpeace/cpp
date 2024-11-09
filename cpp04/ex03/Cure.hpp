#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure:public AMateria
{
	public:
		// Canonical Form
		Cure();
		~Cure();
		Cure(const Cure &copy);
		Cure &operator=(const Cure& copy);
		AMateria* clone() const;

		// Method
		void use(ICharacter& target);

};

#endif
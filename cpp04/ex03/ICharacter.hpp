#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

# include "AMateria.hpp"
/* # include "Ice.hpp"
# include "Cure.hpp" */
class AMateria;
#include <iostream>

// Interface or Purely virtual Class
class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
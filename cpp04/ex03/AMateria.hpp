#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"
class ICharacter;

// Abstract Class
class AMateria
{
	protected:
		std::string _type;
	public:
		// Canonical Form
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(AMateria const & copy);
		AMateria & operator=(AMateria const& copy);
		
		
		// Purely Abstract Method
		virtual AMateria* clone() const = 0;

		// Methods
		virtual void use(ICharacter& target);

		// Getter
		std::string const & getType() const; //Returns the materia type
};

#endif
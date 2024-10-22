#ifndef WRONGANIMAL_HPP
# define WRINGANIMAL_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		void makeSound(void) const;
};

#endif
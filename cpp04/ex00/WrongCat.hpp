#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		// Canonical Form
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat& operator=(const WrongCat& copy);
		
		// Overloaded method
		void makeSound(void) const;
};



#endif
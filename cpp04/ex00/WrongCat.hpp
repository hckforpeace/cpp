#ifndef WRONGANIMAL_HPP
# define WRINGANIMAL_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &obj);
		void makeSound(void) const;
		WrongCat& operator=(const WrongCat& obj);
};

#endif
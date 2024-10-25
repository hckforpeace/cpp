#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &obj);
		std::string getType(void) const;
		void makeSound(void) const;
		WrongAnimal& operator=(const WrongAnimal &obj);
};

#endif
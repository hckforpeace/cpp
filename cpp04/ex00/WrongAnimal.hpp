#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		// Canonical Form
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal& operator=(const WrongAnimal &copy);

		// Method
		void makeSound(void) const;
		
		// Getter
		std::string getType(void) const;
};

#endif
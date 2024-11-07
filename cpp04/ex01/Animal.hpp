#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{
	protected:
		std::string _type;
	public:
		// Canonical Form
		Animal(void);
		virtual ~Animal();
		Animal(std::string type);
		Animal(const Animal &copy);
		Animal &operator=(const Animal& copy);

		// Method(s)
		virtual void makeSound(void) const;
		
		// Getter
		std::string getType(void) const;
};

#endif
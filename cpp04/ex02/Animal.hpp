#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

/* 
	To declare An abstract class you need to make at least one of it's functions purely virtual
	by using "= 0"
	then it will become virtual and not instanciable
	This function Will absolutely need to be implemented in a derived class
*/
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
		virtual void makeSound(void) const = 0;
		
		// Getter
		std::string getType(void) const;
};

#endif
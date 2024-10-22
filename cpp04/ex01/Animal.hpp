#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal &obj);
		virtual void makeSound(void) const;
		Animal &operator=(const Animal& obj);
		std::string getType(void) const;
};

#endif
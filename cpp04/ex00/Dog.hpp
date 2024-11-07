#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal{
	public:
		// Canonical Form
		Dog(void);
		~Dog();
		Dog(const Dog &copy);
		Dog& operator=(const Dog &copy);

		// Overloaded method
		void makeSound(void) const;
};

#endif
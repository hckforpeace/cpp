#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal{
	private:
		Brain *brain;
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
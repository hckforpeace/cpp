#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal{
	public:
		// Canonical Form
		Cat(void);
		~Cat();
		Cat(const Cat &copy);
		Cat& operator=(const Cat &copy);
		
		// Overloaded Method
		void makeSound(void) const;
};

#endif
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *brain;
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
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// const WrongAnimal* meta = new WrongAnimal();
	// const WrongAnimal* i = new WrongAnimal();
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();

	// const Dog* dog = new Dog();
	// const Cat* cat = new Cat();
	// const Dog* copyDog = dog;
	// const Cat* copyCat = cat;

	// copyDog->makeSound(); // will output Dog sound 
	// copyCat->makeSound(); // will output cat sound
	// dog->makeSound(); // will output Dog sound 
	// cat->makeSound(); // will output cat sound

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound(); // will output dog sound

	meta->makeSound();

	// delete cat;
	// delete dog;
	delete meta;
	delete i;
	delete j;
	return 0;
}
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

/* int main()
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
} */

int	main()
{
	Cat g;
	Cat d;

	d = g;

	return 0;
/* 	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const int size = 10;
	Animal* animalstab[size];

	std::cout << std::endl << "***CATS CREATION***" << std::endl;

	for (int i = 0; i < size / 2; i++)
		animalstab[i] = new Cat();

	std::cout << std::endl << "***DOGS CREATION***" << std::endl ;

	for (int i = size / 2; i < size; i++)
		animalstab[i] = new Dog();

	std::cout << std::string(50, '*') << std::endl;

	for (int i = 0; i < size; i++)
		delete animalstab[i];
	delete i;
	delete j;
	return (0); */
}

/* int	main()
{
	Dog basic;
	{
		Dog tmp = basic;
	}
} */

/* int	main()
{
	Dog A = Dog();
	Dog b = A;
	return (0);
} */

/* 	Animal* copycat = animalstab[2];
	copycat->makeSound(); */
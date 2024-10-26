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
/* 	const Animal* Aj = new Dog();
	const Animal* Ai = new Cat(); */
	// const Animal* wrong = new Animal(); // wrong because the class Animal is abstract
	// const Animal no;
	const int size = 10;
	Animal* Aanimalstab[size];

	for (int i = 0; i < size; i++)
	{
		Aanimalstab[i] = NULL;
	}
	for (int i = 0; i < size; i++)
	{
		if (Aanimalstab[i] == NULL)
			std::cout << "NULL" << std::endl;
	}

/* 	for (int i = 0; i < size / 2; i++)
		Aanimalstab[i] = new Cat();

	for (int i = size / 2; i < size; i++)
		Aanimalstab[i] = new Dog();

	for (int i = 0; i < size; i++)
		delete Aanimalstab[i];
	delete Ai;
	delete Aj; */
	return (0);
}
/* 	Animal* copycat = animalstab[2];
	copycat->makeSound(); */
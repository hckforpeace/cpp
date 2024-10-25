#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

std::ostream& operator<<(std::ostream& stream, const Animal &Animal)
{
	stream << "I am an animal of type " << Animal.getType();
	return (stream);
}

std::ostream& operator<<(std::ostream& stream, const WrongAnimal &Animal)
{
	stream << "I am an animal of type " << Animal.getType();
	return (stream);
}

int main()
{
	// 	const WrongAnimal* meta = new WrongAnimal();
	// 	const WrongAnimal* i = new WrongAnimal();
	const Animal* meta = new Animal();
	const Animal* i = new Cat(); 
	const Animal* j = new Dog();

	// assignement operator
/* 	const Dog* dog = new Dog();
	const Cat* cat = new Cat();
	const Dog* copyDog = dog;
	const Cat* copyCat = cat;
	cat->makeSound(); // will output cat sound
	dog->makeSound(); // will output Dog sound 
	std::cout << *copyCat << std::endl;
	std::cout << *copyDog << std::endl;
	copyCat->makeSound(); // will output cat sound
	copyDog->makeSound(); // will output Dog sound  */

	// copy constructor
/* 	Animal copys(*dog);
	std::cout << copys << std::endl; */
	
	std::cout << *j << " " << std::endl;
	std::cout << *i << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound(); // will output dog sound

	meta->makeSound();

	// delete dog;
	// delete cat;
	delete meta;
	delete i;
	delete j;
	return 0;
}
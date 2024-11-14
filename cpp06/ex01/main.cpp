#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main()
{
	Data ptr;
	ptr.age = 12;
	ptr.name = "Pierre";

	std::cout << &ptr << std::endl;
	uintptr_t i = Serializer::serializer(&ptr);
	std::cout << i << std::endl;
	Data *newptr = Serializer::deserialize(i);
	std::cout << newptr << std::endl;

	std::cout << "name: " << newptr->name << ", age: " << newptr->age << std::endl;
	return (0);
}
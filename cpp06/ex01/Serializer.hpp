#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer 
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& copy);
	public:
		static uintptr_t serializer(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
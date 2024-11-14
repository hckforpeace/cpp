#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::Serializer(const Serializer& copy)
{
	(void)copy;
}

Serializer& Serializer::operator=(const Serializer& copy)
{
	(void)copy;
	return (*this);
}

uintptr_t Serializer::serializer(Data* ptr)
{
	uintptr_t iptr = reinterpret_cast<uintptr_t>(ptr);
	return (iptr);
}
Data* Serializer::deserialize(uintptr_t raw)
{
	Data* dptr = reinterpret_cast<Data *>(raw);
	return (dptr);
}
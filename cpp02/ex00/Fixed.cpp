#include "Fixed.hpp"

// Simple setter
void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

// Simple getter
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// default constructor
Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor that calls the operator=
Fixed::Fixed( Fixed &fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(fixed);
}

// operator =overload  
void Fixed::operator=(Fixed const& obj)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->value = obj.getRawBits();
}
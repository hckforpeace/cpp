#include "Fixed.hpp"


// Simple setter
void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

// Simple getter
int	Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// default constructors
Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	this->value = (int)(value << this->fbits);
}

Fixed::Fixed( const float value )
{
	std::cout << "Float constructor called "  << std::endl;
	this->value = roundf(value * (1 << this->fbits));
}

Fixed::Fixed( const Fixed &fixed )
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

float	Fixed::toFloat( void ) const
{
	float res;

	res = (float)this->value / ( 1 << this->fbits);
	return (res);
}

int	Fixed::toInt( void ) const
{
	int res = this->value >> this->fbits;
	return (res);
}

bool	Fixed::operator<(Fixed const& obj)
{
	return this->value < obj.value;
}

bool	Fixed::operator>(Fixed const& obj)
{
	return this->value > obj.value;
}

bool	Fixed::operator==(Fixed const& obj)
{
	return (this->value == obj.value);
}

bool	Fixed::operator<=(Fixed const& obj)
{
	return (operator<(obj) || operator==(obj));
}
bool	Fixed::operator>=(Fixed const& obj)
{
	return (operator>(obj) || operator==(obj));
}

bool	Fixed::operator!=(Fixed const& obj)
{
	return (this->value != obj.value);
}

bool	Fixed::operator+(Fixed const& obj)
{
	return (this->value + obj.value);
}
bool	Fixed::operator-(Fixed const& obj)
{
	return (this->value - obj.value);
}
bool	Fixed::operator*(Fixed const& obj)
{
	return (this->value * obj.value);
}
bool	Fixed::operator/(Fixed const& obj)
{
	return (this->value / obj.value);
}

Fixed	Fixed::operator++()
{
	++this->value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator--()
{
	--this->value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	this->value--;
	return (*this);
}

static Fixed& min(Fixed &obj1, Fixed &obj2)
{

}
const static  Fixed& Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	 if (obj1.value > obj2.value)
	 	return (obj12);
	return obj1;
}
static Fixed& max(Fixed &obj1, Fixed &obj2)
{

}
const static  Fixed& max(const Fixed &obj1, const Fixed &obj2)
{

}
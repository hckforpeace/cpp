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


// converter
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

// destructor
Fixed::~Fixed()
{
}

// default constructors
Fixed::Fixed(void)
{
	this->value = 0;
}

// shifts the bits of value of height to the left
Fixed::Fixed( const int value )
{
	this->value = (int)(value << this->fbits);
}

// shifts bits 1 of heihgt to the left then multiply the value 
Fixed::Fixed( const float value )
{
	this->value = roundf(value * (1 << this->fbits));
}

Fixed::Fixed( const Fixed &fixed )
{
	operator=(fixed);
}


// operator =overload  
Fixed& Fixed::operator=(Fixed const& obj)
{
	this->value = obj.getRawBits();
	return (*this);
}


bool	Fixed::operator<(Fixed const& obj) const
{
	return this->value < obj.value;
}

bool	Fixed::operator>(Fixed const& obj) const
{
	return this->value > obj.value;
}

bool	Fixed::operator==(Fixed const& obj) const
{
	return (this->value == obj.value);
}

bool	Fixed::operator<=(Fixed const& obj) const
{
	return (operator<(obj) || operator==(obj));
}

bool	Fixed::operator>=(Fixed const& obj) const
{
	return (operator>(obj) || operator==(obj));
}

bool	Fixed::operator!=(Fixed const& obj) const
{
	return (this->value != obj.value);
}

Fixed		Fixed::operator+(Fixed const& obj) const
{
	Fixed temp;
	temp.setRawBits(this->value + obj.value);
	return (temp);
}

Fixed		Fixed::operator-(Fixed const& obj) const
{
	Fixed temp;
	temp.setRawBits(this->value - obj.value);
	return (temp);
}

Fixed		Fixed::operator*(Fixed const& obj) const
{
	Fixed temp;
	temp.setRawBits(this->value * obj.value >> fbits);
	return (temp);
}

Fixed		Fixed::operator/(Fixed const& obj) const
{
	Fixed temp;
	temp.setRawBits(this->value * (1 << fbits) / obj.value);
	return (temp);}

Fixed	Fixed::operator++()
{
	++this->value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp;
	temp.value = this->value++;
	return (temp);
}

Fixed	Fixed::operator--()
{
	--this->value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp;
	temp.value = this->value--;
	return (temp);
}

// max / min
const	Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1.value < obj2.value)
		return obj2;
	return obj1;
}

const	Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
	if (obj1.value > obj2.value)
		return obj2;
	return obj1;
}

// const max / min
Fixed& Fixed::max( Fixed& obj1,  Fixed& obj2)
{
	if (obj1 < obj2)
		return obj2;
	return obj1;
}

Fixed& Fixed::min( Fixed& obj1,  Fixed& obj2)
{
	if (obj1 > obj2)
		return obj2;
	return obj1;
}
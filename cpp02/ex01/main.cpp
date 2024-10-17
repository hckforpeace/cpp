#include <iostream>
#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& stream, const Fixed &obj)
{
	stream << obj.toFloat();
	return stream;
}

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}

/* int	main()
{
	int c= 1234.4321f * (1 << 8);
	std::cout << c << std::endl;
	std::cout << (float)c / (1 << 8);
	return (0);
} */
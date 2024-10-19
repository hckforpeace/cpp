#include <iostream>
#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& stream, const Fixed &obj)
{
	stream << obj.toFloat();
	return stream;
}

/* int main( void ) {
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
 */

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

/* int	main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c( Fixed(5) + Fixed(5));
	Fixed const d( Fixed(5.0f) + Fixed(5.0f));
	Fixed const e( Fixed(5.0f) - Fixed(5.0f));

	std::cout << "c <==> 5 + 5: " << c << std::endl;
	std::cout << "d <==> 5.0 + 5.0: " << d << std::endl;
	std::cout << "d <==> 5.0 - 5.0: " << e << std::endl;
	std::cout << "--c: " << --c << std::endl;
	std::cout << "c--: " << c-- << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
} */
#include <iostream>
#include "Point.hpp"

std::ostream& operator<<(std::ostream& stream, const Fixed &obj)
{
	stream << obj.toFloat();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const Point &obj)
{
	stream << "x: " << obj.getX();
	stream << " y: " << obj.getY();
	return stream;
}

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	float	cornerAx;
	float	cornerAy;
	float	cornerBx;
	float	cornerBy;
	float	cornerCx;
	float	cornerCy;
	float	pointx;
	float	pointy;

	std::cout <<"input coordinate x for Corner A of the triangle: ";
	std::cin >> cornerAx;
	std::cout << "input coordinate y for Corner A of the triangle: ";
	std::cin >> cornerAy;

	std::cout << "input coordinate x for Corner B of the triangle: ";
	std::cin >> cornerBx;
	std::cout << "input coordinate y for Corner B of the triangle: ";
	std::cin >> cornerBy;

	std::cout << "input coordinate x for Corner C of the triangle: ";
	std::cin >> cornerCx;
	std::cout << "input coordinate y for Corner C of the triangle: ";
	std::cin >> cornerCy;

	std::cout << "input coordinate x for Point: ";
	std::cin >> pointx;
	std::cout << "input coordinate y for Point: " ;
	std::cin >> pointy;

	Point point(pointx, pointy);
	Point a(cornerAx, cornerAy);
	Point b(cornerBx, cornerBy);
	Point c(cornerCx, cornerCy);
	std::cout << "for point a you choose " << a << std::endl;
	std::cout << "for point b you choose " << b << std::endl;
	std::cout << "for point c you choose " << c << std::endl;
	std::cout << "for point Point you choose " << point << std::endl << "\033[0m";

	if (bsp(a, b, c, point))
		std::cout << "\033[32m" << "The Point is inside the triangle" << "\033[0m" << std::endl;
	else
		std::cout << "\033[31m" << "The Point is outside the triangle" << "\033[0m" << std::endl;
		
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
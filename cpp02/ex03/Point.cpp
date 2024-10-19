#include "Point.hpp"

Point::~Point()
{
}


Point::Point(void):x(Fixed()), y(Fixed())
{
}
Point::Point(const float x, const float y):x(Fixed(x)), y(Fixed(y))
{
}

Point::Point(Point const &p):x(p.x), y(p.y)
{
}

Point&	Point::operator=(Point &obj)
{
	(void)obj;
	// TODO apperently impossible
	return *this;
}

Fixed const Point::getX(void) const
{
	return (this->x);
}

Fixed const Point::getY(void) const
{
	return (this->y);
}

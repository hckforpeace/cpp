#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point{

	private:
		const Fixed x;
		const Fixed y;
	public:
		~Point();
		Point(void);
		Point(const float x, const float y);
		Point(Point const &p);
		Point&	operator=(Point &obj);
		Fixed const getX() const;
		Fixed const getY() const;
};

#endif
#include "Point.hpp"

// Calculates the area p, b, a
float area(Point const p, const Point b , const Point a)
{
	Fixed sum, v1, v2, v3;
	float area;

	v1 = (a.getX() * (b.getY() - p.getY()));
	v2 = (b.getX() * (p.getY() - a.getY()));
	v3 = (p.getX() * (a.getY() - b.getY()));

	sum = (v1 + v2 + v3) / 2;
	area = sum.toFloat();
	if (area < 0)
		area = area * -1;
	if (area == 0)
	{
		std::cout << "the point is on the triangle" << std::endl; 
		return (-1);
	}
	return (area);
}
/* 
	Calculate the area of the triangle
	Calculate the area of the three triangles formed with the Point point and do the sum of them
	compare the sum with the area
*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float t_area = area(a, b, c);

	float a1 = area(point, a, c);
	if (a1 < 0)
		return (0);
	float a2 = area(point, a, b);
	if (a2 < 0)
		return (0);
	float a3 = area(point, b, c);
	if (a3 < 0)
		return (0);

	return (a1 + a2 + a3 == t_area);
}

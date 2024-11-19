#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>


template <typename T> 
void	swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}


template <typename T> 
T const	& min(T const &a, T const &b)
{
	if (a == b)
		return (b);
	if (a < b)
		return (a);
	return (b);
}


template <typename T> 
T const &	max(T const &a, T const &b)
{
	if (a == b)
		return (b);
	if (a < b)
		return (b);
	return (a);
}

#endif
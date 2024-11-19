#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class NoOccurenceFindException: public std::exception
{
	public:
		const char * what() const throw()
		{
			return ("No occurence found !");
		}
};

template <typename T>


typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
		return (it);
	throw NoOccurenceFindException();
};

#endif
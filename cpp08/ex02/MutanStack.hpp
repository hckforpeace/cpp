#ifndef MUTANSTACK_HPP	
#define MUTANSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutanStack: public std::stack<T>
{
	typedef typename std::stack<T>::container_type
};

#endif
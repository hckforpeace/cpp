#ifndef MUTANSTACK_HPP	
#define MUTANSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutanStack: public std::stack<T>
{
	public:
		~MutanStack<T>();
		MutanStack<T>();
		MutanStack<T>(const MutanStack<T>& copy);
		MutanStack<T>& operator=(const MutanStack& copy);


		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::iterator_const const_iterator;

	iterator begin()
	iterator end();
	const_iterator cbegin() const;
	const_iterator cend() const;
};

template <typename T>
MutanStack<T>::MutanStack(void){}

template <typename T>
MutanStack<T>::~MutanStack(void){}

template <typename T>
MutanStack<T>::MutanStack(const MutanStack& copy)
{
	*this = copy;
}

template <typename T>
MutanStack<T>& MutanStack<T>::operator=(const MutanStack& copy)
{
	if (this == &copy)
		return (*this);
	std::stack<T>::operator=(copy);
}
#endif;
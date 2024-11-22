#include "MutantStack.hpp"


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename 		MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const
{
	return (this->c.cbegin());
}

template <typename T>
typename 		MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
	return (this->c.cend());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename 		MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const
{
	return (this->c.crbegin());
}

template <typename T>
typename 		MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const
{
	return (this->c.crend());
}

// Canonical

template <typename T>
MutantStack<T>::~MutantStack<T>()
{

}

template <typename T>
MutantStack<T>::MutantStack( void ) {}


template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy)
{
	MutantStack<T>::operator=(copy);
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> & copy)
{
	if (this == &copy)
		return (*this);
	std::stack<T>::operator=(copy);
	return (*this);
}
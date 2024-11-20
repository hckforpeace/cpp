#ifndef MutantStack_HPP	
#define MutantStack_HPP

#include <iostream>
#include <stack>
template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		~MutantStack<T>();
		MutantStack<T>();
		MutantStack<T>(const MutantStack<T>& copy);
		MutantStack<T>& operator=(const MutantStack& copy);

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin();
		iterator end();
		const_iterator cbegin() const;
		const_iterator cend() const;

		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator crbegin() const;
		const_reverse_iterator crend() const;
};

#include "MutantStack.tpp"
#endif

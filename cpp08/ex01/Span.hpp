#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <exception>
#include <ctime>
#include <cstdlib> 

class Span
{
	private:
		unsigned int _N;
		std::vector<int> tab;
		int	getMax();
		int getMin();
	public:
		// Canonical
		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		Span&	operator=(const Span& copy);

		// Public member functions
		void 	addNumber(int values);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	displayValues();
		static void	display(int element);

		// getter
		const std::vector<int>& getTab(void) const;

		// Exeption
		class FullSpanExcpetion: public std::exception
		{
			const char* what() const throw();
		};

		class SpanTooSmallExcpetion: public std::exception
		{
			const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& stream, const Span &obj);

#endif
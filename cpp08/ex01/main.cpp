#include <iostream>
#include <vector>
#include "Span.hpp"

// Subject tests
int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}

// AddNumber
/* int main()
{
	Span sp = Span(10);

	sp.addNumber();
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	
	try
	{
		sp.addNumber(3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// std::cout << sp;
	return 0;
} */

// Additional test
/* int main()
{
	Span sp = Span(10);

	sp.addNumber(1);
	sp.addNumber(3);
	sp.addNumber(30);
	try
	{
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		// sp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// std::cout << sp;
	return 0;
} */

// addNumbers Method
/* int	main()
{
	std::vector<int> vec;
	vec.assign(3, 5);
	Span span(3);
	try
	{
		span.addNumbers(vec.begin(), vec.end());
		span.displayValues();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
} */
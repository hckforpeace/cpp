#include <iostream>
#include <vector>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << sp ;
	Span sp1 = sp;
	sp.addNumber(11);
	std::cout << std::string(40, '*')  << std::endl <<  sp1 ;
	std::cout << std::string(40, '*')  << std::endl <<  sp ;

	return 0;
}

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


/* int main()
{
	Span sp = Span(10);

	try
	{
		sp.shortestSpan();
		// sp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// std::cout << sp;
	return 0;
} */

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
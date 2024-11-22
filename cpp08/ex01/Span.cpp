#include "Span.hpp"

/* ************************************************************************** */
/*                             Canonical Form                                 */
/* ************************************************************************** */

Span::Span():_N(2){};

Span::Span(unsigned int N):_N(N) {}

Span::Span(const Span& copy)
{
	*this = copy;
}
Span&	Span::operator=(const Span& copy)
{
	if (this == &copy)
		return (*this);
	this->_N = copy._N;
	this->tab = copy.getTab();
	return (*this);
}

/* ************************************************************************** */
/*                             Public member functions                        */
/* ************************************************************************** */

void Span::addNumber(int value)
{
	if (this->tab.size() >= this->_N)
		throw Span::FullSpanExcpetion();
	this->tab.push_back(value);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	unsigned int len = std::distance(begin, end);
	if (len > this->_N)
		throw Span::SpanTooSmallExcpetion();
	this->tab.assign(begin, end);
}

// Static
void	Span::display(int element)
{
	std::cout << element << std::endl;
}

void Span::displayValues()
{
	std::for_each(this->tab.begin(), this->tab.end(), display);
}

int	Span::shortestSpan()
{
	if (this->tab.size() < 2)
		throw Span::SpanTooSmallExcpetion();
	int shortest_span = std::abs(this->tab.at(0) - this->tab.at(1));
	for (std::vector<int>::iterator it = this->tab.begin(); it != this->tab.end(); it++)
	{
		for (std::vector<int>::iterator it2 = it + 1; it2 != this->tab.end(); it2++)
		{
			if (shortest_span > std::abs(*it - *it2))
				shortest_span = std::abs(*it - *it2);
		}
	}
	return (shortest_span);
}
int	Span::longestSpan()
{
	if (this->tab.size() < 2)
		throw Span::SpanTooSmallExcpetion();
	int	min = this->getMin();
	int	max = this->getMax();

	return (max - min);
}

/* ************************************************************************** */
/*                                  Private Getters                           */
/* ************************************************************************** */

int	Span::getMax()
{
	int max = this->tab.at(0);
	for (std::vector<int>::iterator it = tab.begin() + 1; it != tab.end(); it++)
	{
		if (*it > max)
			max = *it;
	}
	return (max);
}
int Span::getMin()
{
	int min = this->tab.at(0);
	for (std::vector<int>::iterator it = tab.begin() + 1; it != tab.end(); it++)
	{
		if (*it < min)
			min = *it;
	}
	return (min);
}

/* ************************************************************************** */
/*                                 Exceptions                                 */
/* ************************************************************************** */

const char * Span::FullSpanExcpetion::what() const throw()
{
	return ("Span is full !");
}

const char * Span::SpanTooSmallExcpetion::what() const throw()
{
	return ("Span too small !");
}

/* ************************************************************************** */
/*                                  Public Getter                             */
/* ************************************************************************** */

const std::vector<int>&	Span::getTab(void) const
{
	return this->tab;
}


/* ************************************************************************** */
/*                             Overload operator                              */
/* ************************************************************************** */
std::ostream& operator<<(std::ostream& stream, const Span &obj)
{
	std::vector<int> tab = obj.getTab();
	for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); it++)
			stream << *it << std::endl;
	return (stream);
}
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string* param, int size)
{

}



void PmergeMe::parse_add( std::string str )
{
	int	number;
	if (!is_integer(str))
		throw std::runtime_error("Error" + str + "not an integer !");
	// if ()
	std::stringstream sstr;
	sstr << str;
	sstr >> number;
	if (number < 0)
		throw std::runtime_error("Error" + str + "not an integer !");

}

bool PmergeMe::is_integer(std::string str)
{
	std::string::iterator it = str.begin();
	if (*it == '0' && str.size() != 1)
		return (false);
	if (*it == )
	for (; it != str.end(); it++)
	{
		if (!(*it >= '0' && *it <= '9'))
				return (false);
	}
	return (true);
}

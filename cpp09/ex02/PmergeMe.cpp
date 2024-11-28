#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string* param, int size)
{

}



void PmergeMe::parse_add( std::string str )
{
	if (!is_integer(str))
		throw std::runtime_error("Error" + str + "not an integer !");
	if ()
}

bool PmergeMe::is_integer(std::string str)
{
std::string::iterator it = str.begin()
	for (; it != str.end(); it++)
	{
			if (!(*it >= '0' && *it <= '9'))
					return (false);
	}
	return (true);
}

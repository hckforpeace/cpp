#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>

class PmergeMe
{
	private:
		std::vector<int> tabv;
	public:
		PmergeMe(std::string* param, int size);
		void parse_add(std::string str);
		bool is_integer(std::string str);
};

#endif
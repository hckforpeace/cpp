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
		void display(std::vector<int> tab);
		void sort_pair(std::vector<int> &tab, int pairs);
		static bool is_sorted(std::vector<int> tabv, int begin, int steps);
		static int	get_max(std::vector<int> tabv, int begin, int steps);
		static void	swap(std::vector<int> &tabv, int begin, int steps);
};

void sort2(std::vector<int>& tab);
int get_max(std::vector<int>& left, std::vector<int>& right);

#endif
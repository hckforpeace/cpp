#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <deque>

class PmergeMe
{
	private:
		std::vector<int> tabv;
		std::deque<int> tabq;
	public:
		PmergeMe();
		PmergeMe(std::string* param, int size);
		~PmergeMe(){};
		PmergeMe(PmergeMe &cpy);
		PmergeMe &operator=(PmergeMe &copy);

		//Public functions
		void parse_add(std::string str);
		bool is_integer(std::string str);
		void display(std::vector<int> tab, int pairs);
		void display_deque(std::deque<int> tabs);
		void ford_johnson_vec(std::vector<int> &tab, int pairs);
		void ford_johnson_deque(std::deque<int> &tab, int pairs);

		// Public static functions
		static bool is_sorted(std::vector<int> tabv, int begin, int steps);
		static bool is_sorted_deque(std::deque<int> tabv, int begin, int steps);
		static int	get_max(std::vector<int> tabv, int begin, int steps);
		static int	get_max_deque(std::deque<int> tabv, int begin, int steps);
		static void	swap(std::vector<int> &tabv, int begin, int steps);
		static void	swap_deque(std::deque<int> &tabv, int begin, int steps);
		static void	binary_insertion(std::vector<int> &tab, int tab_idx, std::vector<int> &element, int idx_element, int pair);
		static void	binary_insertion_deque(std::deque<int> &tab, int tab_idx, std::deque<int> &element, int idx_element, int pair);
		static int	get_Jacobsthal(int i);
		static bool is_sorted(std::vector<int> tabv);
		static bool is_sorted(std::deque<int> tabq);
		// static int get_a_of_b(std::vector<int>())
};

void sort2(std::vector<int>& tab);
int get_max(std::vector<int>& left, std::vector<int>& right);

#endif
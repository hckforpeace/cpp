#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string* param, int size)
{
	for (int i = 0; i < size; i++)
		parse_add(param[i]);
	sort_pair(this->tabv, 2);
	display(this->tabv, -1);
}

void PmergeMe::parse_add( std::string str )
{
	int	number;
	if (!is_integer(str))
		throw std::runtime_error("Error: " + str + " not an integer !");
	std::stringstream sstr;
	sstr << str;
	sstr >> number;
	if (number < 0)
		throw std::runtime_error("Error: " + str + " negative integer !");
	this->tabv.push_back(number);
}

bool PmergeMe::is_integer(std::string str)
{
	std::string::iterator it = str.begin();
	if (*it == '0' && str.size() != 1)
		return (false);
	for (; it != str.end(); it++)
	{
		if (!(*it >= '0' && *it <= '9'))
				return (false);
	}
	return (true);
}

void PmergeMe::display(std::vector<int> tab, int pairs)
{
	int i = 0;
	for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); it++)
	{
		if (i == 0)
			std::cout << "(";
		std::cout << *it;
		if (i == (pairs / 2 - 1))
			std::cout << ", ";
		else if (it + 1 != tab.end())
			std::cout << " ";
		if (i == pairs - 1)
		{
			std::cout << ")";		
			i = 0;
		}
		else 
			i++;
	}
	std::cout << std::endl;
}


/* std::vector<int> *PmergeMe::sort_pair(std::vector<int> *tab)
{
	std::vector<int> *left;
	std::vector<int> *right;
	std::vector<int> left_temp;
	std::vector<int> right_temp;
	std::vector<int> *ret;
	int size = tab->size();

	
	if (size == 1)
		return (tab);

	if ((size / 2) % 2 == 1)
	{
		left_temp.insert(left_temp.begin(), tab->begin(), tab->begin() + (size / 2));
		right_temp.insert(right_temp.begin(), tab->begin() + (size / 2), tab->end());
	}
	else
	{
		left_temp.insert(left_temp.begin(), tab->begin(), tab->begin() + (size / 2) + 1);
		right_temp.insert(right_temp.begin(), tab->begin() + (size / 2) + 1, tab->end());
	}

	std::cout << "left size: " << left_temp.size() << std::endl;
	display(left_temp);
	std::cout << "right size: " << right_temp.size() << std::endl;
	display(right_temp);
	std::cout << std::string(50, '*') << std::endl;


	left = sort_pair(&left_temp);
	right = sort_pair(&right_temp);

	// std::cout << "left size: " << left->size() << std::endl;
	// display(*left);
	// std::cout << "right size: " << right->size() << std::endl;
	// display(*right);
	// std::cout << std::string(50, '*') << std::endl;

	if (get_max(*left, *right) == 0)
	{
		ret = new std::vector<int>(right->begin(), right->end());
		ret->insert(ret->begin() + ret->size(), left->begin(), left->end());
	}
	else
	{
		ret = new std::vector<int>(left->begin(), left->end());
		ret->insert(ret->begin() + ret->size(), right->begin(), right->end());
	}
	if (size % 2)
		ret->insert(ret->begin() + ret->size(), tab->back());
	// std::cout << "ret :";
	// display(*ret);
	if (tab->size() >= 8)
	{
		delete left;
		delete right;
	}
	return (ret);
} */

int	PmergeMe::get_Jacobsthal(int i)
{
	int jacobsthal[16] = {1, 3, 15, 55, 231, 903, 3655, 14535, 58311, 232903, 932295,  3727815, 14913991, 59650503, 238612935, 954429895};
	return (jacobsthal[i - 1]);
}

int	PmergeMe::get_max(std::vector<int> tabv, int idx, int end)
{
	int max = tabv[idx];
	while (idx < end)
	{
		if (idx + 1 == end)
			return (max);
		if (max < tabv[idx + 1])
			max = tabv[idx + 1];
		idx++;
	}
	return (max);
}

bool PmergeMe::is_sorted(std::vector<int> tabv, int begin, int steps)
{
/* 		std::cerr << "not sorted" << std::endl;
	if (steps == 1)
	{
		std::cout << "Comparing: " << tabv[begin] << " and " << tabv[begin + 1] << std::endl;
		if (tabv[begin] > tabv[begin + 1])
			return (false);
		return (true);
	} */
	int max_left = get_max(tabv, begin, begin + steps / 2);
	int max_right = get_max(tabv, begin + (steps / 2), begin + steps);
	std::cerr << "left: " << max_left << " right: " << max_right << " steps: " << steps << std::endl;
	if (max_left < max_right)
		return (true);
	return (false);
}

void	PmergeMe::swap(std::vector<int> &tabv, int begin, int steps)
{
/* 	if (steps == 1)
	{
		int temp = tabv[begin];
		tabv[begin] = tabv[begin + 1];
		tabv[begin + 1] = temp;
		return ;
	} */
	std::cout << "begin: " << begin << ", steps: " << steps << std::endl;
	std::vector<int> temp;
	temp.insert(temp.begin(), tabv.begin() + begin, tabv.begin() + begin + (steps / 2));
	
	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
		std::cout << "Iterator: " << *it  << std::endl ;
	std::cout << "size: " << temp.size() << std::endl;
	for (int i = begin; i < begin + (steps / 2); i++)
	{
		std::cout << "copying: " << tabv[i + (steps / 2)] << std::endl;
		tabv[i] = tabv[i + (steps / 2)]; 
	}
	for (int i = begin + (steps / 2); i < begin + steps; i++)
	{
		// std::cout << "tabv[" << i << "]" << " = " << "temp[" << (begin + (steps / 2)) - i << "]" << " = " << temp[(begin + (steps / 2)) - i] << std::endl;
		tabv[i] = temp[i - (begin + (steps / 2))];
	}
	// tabv.insert(tabv.begin() + begin + (steps / 2) - 1, temp.begin(), temp.end());
}

void	PmergeMe::binary_insertion(std::vector<int> &tab, int tab_idx, std::vector<int> element, int idx_element, int pair)
{
	while (tab_idx > 0 && tab[tab_idx] > element[idx_element])
	{
		tab_idx -= pair / 2;
	}
	// std::cout << "tab_idx: " << tab_idx  << ", tab[tab_idx]" << tab[tab_idx] << std::endl;
	// std::cout << "idx: " <<idx_element - (pair / 2) + 1 << " element[idx_element], " << element[idx_element] << std::endl;
	// std::cerr << "ici" << std::endl;
	if (tab_idx <= 0)
		tab.insert(tab.begin(), element.begin() + idx_element - (pair / 2) + 1, element.begin() + idx_element + 1);
	else
		tab.insert(tab.begin() + tab_idx + 1, element.begin() + idx_element - (pair / 2) + 1, element.begin() + idx_element + 1);
}

void PmergeMe::sort_pair(std::vector<int> &tab, int pairs)
{
	std::vector<int> main;
	std::vector<int> pend;
	std::vector<int> odd;
	int jacobs_num;
	int main_anum = 0; 

	int size = tab.size(); 
	if (size / (pairs / 2)	 < 2)
		return ;
	std::cout << std::string(50, '*') << pairs << std::endl;
	for (int i = 0; i < size; i += pairs)
	{
		if (i + pairs > size)
		{
			std::cerr << "i + pairs=" << i+ pairs << ">=" << size << "IMPOSSIBLE" << std::endl;
			break;
		}
		if (!is_sorted(tab, i, pairs))
			swap(tab, i, pairs);
		display(tab, pairs);
	}
	sort_pair(tab, pairs * 2);

	// Insert in the main {a1, b1}
	main.insert(main.begin(), tab.begin(), tab.begin() + pairs);

	// Insert all the a's in the main
	std::cout << "Pairs: " << pairs << std::endl;
	for (int i = pairs; i < size; i += pairs)
	{
		if (i + (pairs) >= size)
		{
			// Insert in the odd
			if (i + pairs / 2 < size)
				odd.insert(odd.begin(), tab.begin() + pairs + (pairs * main_anum), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2));
			// TODO Put the odd			
			break ;
		}
		// std::cout << "i: " << i << std::endl;
		// std::cout << "pairs: " << pairs << std::endl;
		// std::cout << "main_size: " << main.size() << std::endl;
		// std::cout << "from: " << pairs + (pairs * main_anum) + (pairs / 2) << ", to : " << pairs + (pairs * main_anum) + pairs << std::endl;
		// Insert in the main
		main.insert(main.begin() + main.size(), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2), tab.begin() + pairs + (pairs * main_anum) + pairs);
		// Insert in the pend
		pend.insert(pend.begin() + pend.size(), tab.begin() + pairs + (pairs * main_anum), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2));
		main_anum++;
	}

	int i = 1;
	int	initial_main_size = main.size();
	int	initial_pend = pend.size();
	int	initial_main_size = main.size();
	int inserted_from_pend = 0;
	int	idx_of_pend_insert;
	while (pend.size() != 0)
	{
		jacobs_num = get_Jacobsthal(i);
		i++;
		while (jacobs_num != 0)
		{
			idx_of_pend_insert = initial_pend - jacobs_num	;

		}
	}

	std::cout << "tab: ";
	display(tab, -1);
	std::cout << "main :"; 
	display(main, pairs);
	std::cout << "pend :"; 
	display(pend, pairs);
	std::cout << "odd :"; 
	display(odd, pairs);
	// binary_insertion(tab[7], pend, 3);
}




void sort2(std::vector<int>& tab)
{
	int temp;
	if (tab[0] < tab[1])
		return ;
	temp = tab[0];
	tab[0] = tab[1];
	tab[1] = temp;
}

int get_max(std::vector<int>& left, std::vector<int>& right)
{
	// int size;
	int max_left;
	int	max_right;

	// if (left.size() < right.size())
		// size =  left.size();
	// else
		// size = right.size();
	std::vector<int>::iterator it = left.begin();
	max_left = *it;
	it++;
	for (; it != left.end(); it++)
	{
		if (*it > max_left)
			max_left = *it;
	}

	it = right.begin();
	max_right = *it;
	it++;
	for (; it != right.end(); it++)
	{
		if (*it > max_right)
			max_right = *it;
	}

	if (max_right > max_left)
		return (1);
	return (0);
}
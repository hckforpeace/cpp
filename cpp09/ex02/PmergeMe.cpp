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
	if (i > 0)
	{
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
	}
	else
	{
		for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); it++)
		{
			std::cout << *it << " ";	
		}
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

// TODO 	numbers are wrong
int	PmergeMe::get_Jacobsthal(int i)
{
	int jacobsthal[30] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};
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
	// std::cerr << "left: " << max_left << " right: " << max_right << " steps: " << steps << std::endl;
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
	// std::cout << "begin: " << begin << ", steps: " << steps << std::endl;
	std::vector<int> temp;
	temp.insert(temp.begin(), tabv.begin() + begin, tabv.begin() + begin + (steps / 2));
	
	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
		// std::cout << "Iterator: " << *it  << std::endl ;
	// std::cout << "size: " << temp.size() << std::endl;
	for (int i = begin; i < begin + (steps / 2); i++)
	{
		// std::cout << "copying: " << tabv[i + (steps / 2)] << std::endl;
		tabv[i] = tabv[i + (steps / 2)]; 
	}
	for (int i = begin + (steps / 2); i < begin + steps; i++)
	{
		// std::cout << "tabv[" << i << "]" << " = " << "temp[" << (begin + (steps / 2)) - i << "]" << " = " << temp[(begin + (steps / 2)) - i] << std::endl;
		tabv[i] = temp[i - (begin + (steps / 2))];
	}
	// tabv.insert(tabv.begin() + begin + (steps / 2) - 1, temp.begin(), temp.end());
}

void	PmergeMe::binary_insertion(std::vector<int> &tab, int tab_idx, std::vector<int> &element, int idx_element, int pair)
{
	while (tab_idx >= 0 && tab[tab_idx] > element[idx_element])
	{
		std::cout << tab[tab_idx] << " < " << element[idx_element] << std::endl;
		tab_idx -= pair / 2;
	}
	// std::cout << "tab_idx: " << tab_idx  << ", tab[tab_idx]" << tab[tab_idx] << std::endl;
	// std::cout << "idx: " <<idx_element - (pair / 2) + 1 << " element[idx_element], " << element[idx_element] << std::endl;
	// std::cerr << "ici" << std::endl;
	if (tab_idx < 0)
	{
		tab.insert(tab.begin(), element.begin() + idx_element - (pair / 2) + 1, element.begin() + idx_element + 1);
	}
	else
	{
		tab.insert(tab.begin() + tab_idx + 1, element.begin() + idx_element - (pair / 2) + 1, element.begin() + idx_element + 1);
	}
	element.erase(element.begin() + idx_element - (pair / 2) + 1, element.begin() + idx_element + 1);
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
			// std::cerr << "i + pairs=" << i+ pairs << ">=" << size << "IMPOSSIBLE" << std::endl;
			break;
		}
		if (!is_sorted(tab, i, pairs))
			swap(tab, i, pairs);
		// display(tab, pairs);
	}
	sort_pair(tab, pairs * 2);
	std::cout << std::string(50, '*') << ", depiler lvl: " << pairs << std::endl;
	// Insert in the main {a1, b1}
	main.insert(main.begin(), tab.begin(), tab.begin() + pairs);

	display(tab, pairs);
	// Insert all the a's in the main
	std::cout << "Pairs: " << pairs << std::endl;
	for (int i = pairs; i < size; i += pairs)
	{
		if (i + (pairs) > size)
		{
			// Insert in the odd
			std::cout << "Enregistrer les OODDDDSS" << "i + pairs / 2: " << i + (pairs / 2) << std::endl;
			std::cout << "size" << size <<  std::endl;
			if (i + (pairs / 2) - 1 < size)
			{
				std::cout << "ici" << std::endl;
				odd.insert(odd.begin(), tab.begin() + pairs + (pairs * main_anum), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2));
			}
			// TODO Put the odd
			break ;
		}
		main.insert(main.begin() + main.size(), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2), tab.begin() + pairs + (pairs * main_anum) + pairs);
		// Insert in the pend
		pend.insert(pend.begin() + pend.size(), tab.begin() + pairs + (pairs * main_anum), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2));
		main_anum++;
	}

	int i = 1;
	int	initial_main_size = main.size();
	int	initial_pend_size = pend.size();
	int pairs_to_insert_in_main;
	int	pos_to_insert;
	int inserted_from_pend = 0;
	int	number_of_first_pend;
	int a;
	int b;

	std::cout << "main: ";
	display(main, pairs);
	std::cout << "pend: ";
	display(pend, pairs);
	std::cout << "odd: ";
	display(odd, pairs);
	if (pend.size() != 0)
	{
		while (pend.size() != 0)
		{
			jacobs_num = get_Jacobsthal(i);
			i++;
			number_of_first_pend = inserted_from_pend + 2;
			std::cout << "number_of_first_pend: " << number_of_first_pend << std::endl;
			if (jacobs_num > pend.size() / (pairs / 2))
			{
				std::cout << "OUT" << std::endl;
				pos_to_insert = pend.size() - 1;
				jacobs_num = pend.size() / (pairs / 2) + 1;
				std::cout << "new num jacob: " << jacobs_num << std::endl;
			}
			// std::cout << "idx of b: " << pos_to_insert << std::endl;
			b = (jacobs_num - 1) * (pairs / 2) - 1;
			pairs_to_insert_in_main = (b + 1) / (pairs / 2);
			// break ;
			for (int i = 0; i < pairs_to_insert_in_main; i++)
			{
				a = (inserted_from_pend + jacobs_num) * (pairs / 2) - 1;
				std::cout << "a: " << a << std::endl;
				b = (jacobs_num - 1) * (pairs / 2) - 1;
				std::cout << "b: " << b << std::endl;
				binary_insertion(main, a, pend, b, pairs);

				//
				std::cout << "LOOP: " << std::endl;
				std::cout << "main: ";
				display(main, pairs);
				std::cout << "pend: ";
				display(pend, pairs);
				std::cout << "odd: ";
				display(odd, pairs);
				jacobs_num--;
				inserted_from_pend++;
			}
			std::cout << "loop end" << std::endl;
		}
	}
	// display(tab);
	if (odd.size() != 0)
	{
		binary_insertion(main, (main.size() - 1 - (pairs / 2)), odd, odd.size() - 1, pairs);

	}
	display(main, pairs);

	tab.erase(tab.begin(), tab.end());
	tab.insert(tab.begin(), main.begin(), main.end());
	std::cout << "here" << std::endl;

	// display(tab, pairs);

	// std::cout << "tab: ";
	// display(tab, -1);
	// std::cout << "main :"; 
	// display(main, pairs);
	// std::cout << "pend :"; 
	// display(pend, pairs);
	// std::cout << "odd :"; 
	// display(odd, pairs);
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
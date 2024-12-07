#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string* param, int size)
{
	for (int i = 0; i < size; i++)
		parse_add(param[i]);
	std::cout << "Before: ";
	display_deque(this->tabq);


	clock_t start = clock();
	ford_johnson_deque(this->tabq, 2);
	clock_t end = clock();

	std::cout << "After:  ";
	display_deque(this->tabq);

	double elapsed_time = static_cast<double>(double(end - start)) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << tabq.size() <<" elements with std::vector<int> : " << elapsed_time  << " us" << std::endl;

	start = clock();
	ford_johnson_vec(this->tabv, 2);
	end = clock();
	elapsed_time = static_cast<double>(double(end - start)) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << tabv.size() <<" elements with std::deque<int>  : " << elapsed_time << " us" << std::endl;

	if (is_sorted(this->tabv) && is_sorted(this->tabq))
		std::cout << "CONGRATS IT'S SORTED" << std::endl;
	else
		std::cout << "NOT SORTED" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */
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
	this->tabq.push_back(number);
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

void PmergeMe::ford_johnson_deque(std::deque<int> &tab, int pairs)
{
	std::deque<int> main;
	std::deque<int> pend;
	std::deque<int> odd;
	std::deque<int> temp;
	int jacobs_num;
	int main_anum = 0; 

	int size = tab.size(); 
	if (size / (pairs / 2)	 < 2)
		return ;
	// std::cout << std::string(50, '*') << pairs << std::endl;
	for (int i = 0; i < size; i += pairs)
	{
		if (i + pairs > size)
		{
			// std::cerr << "i + pairs=" << i+ pairs << ">=" << size << "IMPOSSIBLE" << std::endl;
			break;
		}
		if (!is_sorted_deque(tab, i, pairs))
			swap_dequeu(tab, i, pairs);
		// display(tab, pairs);
	}
	ford_johnson_deque(tab, pairs * 2);
	// std::cout << std::string(50, '*') << ", depiler lvl: " << pairs << std::endl;
	// Insert in the main {a1, b1}
	main.insert(main.begin(), tab.begin(), tab.begin() + pairs);

	// display(tab, pairs);
	// Insert all the a's in the main
	// std::cout << "Pairs: " << pairs << std::endl;
	for (int i = pairs; i < size; i += pairs)
	{
		if (i + (pairs) > size)
		{
			// Insert in the odd
			if (i + (pairs / 2) - 1 < size)
				odd.insert(odd.begin(), tab.begin() + pairs + (pairs * main_anum), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2));
			if (tab.size() % (pairs / 2) != 0)
			{
				// std::cout << "OUT HERE: " << tab.size() % (pairs / 2) << std::endl;
				temp.insert(temp.begin(), tab.end() - (tab.size() % (pairs / 2)) , tab.end());
				// std::cout << "temp: " << std::endl;
				// display(temp, -1);
			}
			break ;
		}
		main.insert(main.begin() + main.size(), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2), tab.begin() + pairs + (pairs * main_anum) + pairs);
		// Insert in the pend
		pend.insert(pend.begin() + pend.size(), tab.begin() + pairs + (pairs * main_anum), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2));
		main_anum++;
	}

	int i = 1;
	int pairs_to_insert_in_main;
	int inserted_from_pend = 0;
	int	number_of_first_pend;
	int a;
	int b;
	unsigned int comp;

	// std::cout << "main: ";
	// display(main, pairs);
	// std::cout << "pend: ";
	// display(pend, pairs);
	// std::cout << "odd: ";
	// display(odd, pairs);
	if (pend.size() != 0)
	{
		while (pend.size() != 0)
		{
			jacobs_num = get_Jacobsthal(i);
			i++;
			number_of_first_pend = inserted_from_pend + 2;
			b = (((jacobs_num + 1) - (number_of_first_pend)) * (pairs / 2)) - 1;
			if (b > (pend.size() - 1))
			{
				// std::cout << "Changin Jacobsthal number" << std::endl;;
				b = pend.size() - 1;
				jacobs_num = number_of_first_pend + ((pend.size() / (pairs / 2)));
			}
			// // else 
			// if ((b + 1) % (pairs / 2) != 0)
			// {
			// 	std::cout << "iICI" << std::endl;
			// 	b++;
			// }
			pairs_to_insert_in_main = (b + 1) / (pairs / 2);
			// std::cout << "Numbers of inserted from pend " << number_of_first_pend << std::endl;
			// std::cout << "**b: " << b << std::endl;
			// std::cout << "inserted from pend: " << inserted_from_pend << std::endl;
			// std::cout << "number of the first pend: " << number_of_first_pend << std::endl;
			// std::cout << "Jacobsthal Number: " << jacobs_num << std::endl;
			// std::cout << "Pairs to insert: " << pairs_to_insert_in_main << std::endl;
			// break ;
			for (int i = 0; i < pairs_to_insert_in_main; i++)
			{
				a = (inserted_from_pend + jacobs_num) * (pairs / 2) - 1;
				// std::cout << "a: " << a << std::endl;
				// b = (jacobs_num - 1) * (pairs / 2) - 1;
				// std::cout << "b: " << b << std::endl;
				binary_insertion_deque(main, a, pend, b, pairs);

				// std::cout << "LOOP: " << std::endl;
				// std::cout << "main: ";
				// display(main, pairs);
				// std::cout << "pend: ";
				// display(pend, pairs);
				// std::cout << "odd: ";
				// display(odd, pairs);
				b -= (pairs / 2);
				jacobs_num--;
				inserted_from_pend++;
			}
			// std::cout << "loop end" << std::endl;
		}
		// display(tab);
		if (odd.size() != 0)
			binary_insertion_deque(main, (main.size() - 1), odd, odd.size() - 1, pairs);
		tab.erase(tab.begin(), tab.end());
		tab.insert(tab.begin(), main.begin(), main.end());
		if (temp.size() != 0)
			tab.insert(tab.begin() + tab.size(), temp.begin(), temp.end());
	}
	else if (odd.size() != 0)
	{
		binary_insertion_deque(main, (main.size() - 1), odd, odd.size() - 1, pairs);
		tab.erase(tab.begin(), tab.end());
		tab.insert(tab.begin(), main.begin(), main.end());
		if (temp.size() != 0)
			tab.insert(tab.begin() + tab.size(), temp.begin(), temp.end());
	}
	// display(main, pairs);

	// std::cout << "here" << std::endl;

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

void PmergeMe::ford_johnson_vec(std::vector<int> &tab, int pairs)
{
	std::vector<int> main;
	std::vector<int> pend;
	std::vector<int> odd;
	std::vector<int> temp;
	int jacobs_num;
	int main_anum = 0; 

	int size = tab.size(); 
	if (size / (pairs / 2)	 < 2)
		return ;
	// std::cout << std::string(50, '*') << pairs << std::endl;
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
	ford_johnson_vec(tab, pairs * 2);
	// std::cout << std::string(50, '*') << ", depiler lvl: " << pairs << std::endl;
	// Insert in the main {a1, b1}
	main.insert(main.begin(), tab.begin(), tab.begin() + pairs);

	// display(tab, pairs);
	// Insert all the a's in the main
	// std::cout << "Pairs: " << pairs << std::endl;
	for (int i = pairs; i < size; i += pairs)
	{
		if (i + (pairs) > size)
		{
			// Insert in the odd
			if (i + (pairs / 2) - 1 < size)
				odd.insert(odd.begin(), tab.begin() + pairs + (pairs * main_anum), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2));
			if (tab.size() % (pairs / 2) != 0)
			{
				// std::cout << "OUT HERE: " << tab.size() % (pairs / 2) << std::endl;
				temp.insert(temp.begin(), tab.end() - (tab.size() % (pairs / 2)) , tab.end());
				// std::cout << "temp: " << std::endl;
				// display(temp, -1);
			}
			break ;
		}
		main.insert(main.begin() + main.size(), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2), tab.begin() + pairs + (pairs * main_anum) + pairs);
		// Insert in the pend
		pend.insert(pend.begin() + pend.size(), tab.begin() + pairs + (pairs * main_anum), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2));
		main_anum++;
	}

	int i = 1;
	int pairs_to_insert_in_main;
	int inserted_from_pend = 0;
	int	number_of_first_pend;
	int a;
	int b;
	unsigned int comp;

	// std::cout << "main: ";
	// display(main, pairs);
	// std::cout << "pend: ";
	// display(pend, pairs);
	// std::cout << "odd: ";
	// display(odd, pairs);
	if (pend.size() != 0)
	{
		while (pend.size() != 0)
		{
			jacobs_num = get_Jacobsthal(i);
			i++;
			number_of_first_pend = inserted_from_pend + 2;
			b = (((jacobs_num + 1) - (number_of_first_pend)) * (pairs / 2)) - 1;
			if (b > (pend.size() - 1))
			{
				// std::cout << "Changin Jacobsthal number" << std::endl;;
				b = pend.size() - 1;
				jacobs_num = number_of_first_pend + ((pend.size() / (pairs / 2)));
			}
			pairs_to_insert_in_main = (b + 1) / (pairs / 2);
			// std::cout << "Numbers of inserted from pend " << number_of_first_pend << std::endl;
			// std::cout << "**b: " << b << std::endl;
			// std::cout << "inserted from pend: " << inserted_from_pend << std::endl;
			// std::cout << "number of the first pend: " << number_of_first_pend << std::endl;
			// std::cout << "Jacobsthal Number: " << jacobs_num << std::endl;
			// std::cout << "Pairs to insert: " << pairs_to_insert_in_main << std::endl;
			for (int i = 0; i < pairs_to_insert_in_main; i++)
			{
				a = (inserted_from_pend + jacobs_num) * (pairs / 2) - 1;
				// std::cout << "a: " << a << std::endl;
				// b = (jacobs_num - 1) * (pairs / 2) - 1;
				// std::cout << "b: " << b << std::endl;
				binary_insertion(main, a, pend, b, pairs);

				// std::cout << "LOOP: " << std::endl;
				// std::cout << "main: ";
				// display(main, pairs);
				// std::cout << "pend: ";
				// display(pend, pairs);
				// std::cout << "odd: ";
				// display(odd, pairs);
				b -= (pairs / 2);
				jacobs_num--;
				inserted_from_pend++;
			}
		}
		if (odd.size() != 0)
			binary_insertion(main, (main.size() - 1), odd, odd.size() - 1, pairs);
		tab.erase(tab.begin(), tab.end());
		tab.insert(tab.begin(), main.begin(), main.end());
		if (temp.size() != 0)
			tab.insert(tab.begin() + tab.size(), temp.begin(), temp.end());
	}
	else if (odd.size() != 0)
	{
		binary_insertion(main, (main.size() - 1), odd, odd.size() - 1, pairs);
		tab.erase(tab.begin(), tab.end());
		tab.insert(tab.begin(), main.begin(), main.end());
		if (temp.size() != 0)
			tab.insert(tab.begin() + tab.size(), temp.begin(), temp.end());
	}
}


// void sort2(std::vector<int>& tab)
// {
// 	int temp;
// 	if (tab[0] < tab[1])
// 		return ;
// 	temp = tab[0];
// 	tab[0] = tab[1];
// 	tab[1] = temp;
// }

// int get_max(std::vector<int>& left, std::vector<int>& right)
// {
// 	// int size;
// 	int max_left;
// 	int	max_right;

// 	// if (left.size() < right.size())
// 		// size =  left.size();
// 	// else
// 		// size = right.size();
// 	std::vector<int>::iterator it = left.begin();
// 	max_left = *it;
// 	it++;
// 	for (; it != left.end(); it++)
// 	{
// 		if (*it > max_left)
// 			max_left = *it;
// 	}

// 	it = right.begin();
// 	max_right = *it;
// 	it++;
// 	for (; it != right.end(); it++)
// 	{
// 		if (*it > max_right)
// 			max_right = *it;
// 	}

// 	if (max_right > max_left)
// 		return (1);
// 	return (0);

// }

bool PmergeMe::is_sorted(std::vector<int> tabv)
{
	for (std::vector<int>::iterator it = tabv.begin(); it != tabv.end(); it++)
	{
		if (it + 1 == tabv.end())
			return (true);
		if (*it > *(it + 1))
		{
			std::cout << *it << std::endl;
 			return (false);
		}
	}
	return (true);
}

bool PmergeMe::is_sorted_deque(std::deque<int> tabv, int begin, int steps)
{
	int max_left = get_max_deque(tabv, begin, begin + steps / 2);
	int max_right = get_max_deque(tabv, begin + (steps / 2), begin + steps);
	if (max_left < max_right)
		return (true);
	return (false);
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

int	PmergeMe::get_max_deque(std::deque<int> tabq, int idx, int end)
{
	std::deque<int>::iterator it = tabq.begin() + idx;
	int max = *it;
	for (int i = idx; i < end; i++)
	{
		if (max < tabq[i])
			max = tabq[i];
	}
	return (max);
}

void	PmergeMe::swap(std::vector<int> &tabv, int begin, int steps)
{
	std::vector<int> temp;
	temp.insert(temp.begin(), tabv.begin() + begin, tabv.begin() + begin + (steps / 2));
	
	// for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
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

void	PmergeMe::swap_dequeu(std::deque<int> &tabv, int begin, int steps)
{
	std::vector<int> temp;
	temp.insert(temp.begin(), tabv.begin() + begin, tabv.begin() + begin + (steps / 2));
	
	// for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
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
}


void	PmergeMe::binary_insertion(std::vector<int> &tab, int tab_idx, std::vector<int> &element, int idx_element, int pair)
{
	while (tab_idx >= 0 && tab[tab_idx] > element[idx_element])
	{
		tab_idx -= pair / 2;
	}
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

void	PmergeMe::binary_insertion_deque(std::deque<int> &tab, int tab_idx, std::deque<int> &element, int idx_element, int pair)
{
	std::deque<int>::iterator itt = tab.begin() + tab_idx;
	std::deque<int>::iterator ite = element.begin() + idx_element;
	while (tab_idx >= 0 && *itt > *ite)
	{
		tab_idx -= pair / 2;
		if (tab_idx <= 0)
			itt = tab.begin();
		else
			itt -= (pair / 2);
	}
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

int	PmergeMe::get_Jacobsthal(int i)
{
	int jacobsthal[30] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765};
	return (jacobsthal[i - 1]);
}

void PmergeMe::display_deque(std::deque<int> tabv)
{
	for (std::deque<int>::iterator it = tabv.begin(); it != tabv.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

bool PmergeMe::is_sorted(std::deque<int> tabq)
{
	for (std::deque<int>::iterator it = tabq.begin(); it != tabq.end(); it++)
	{
		if (it + 1 == tabq.end())
			return (true);
		if (*it > *(it + 1))
		{
			std::cout << *it << std::endl;
 			return (false);
		}
	}
	return (true);
}
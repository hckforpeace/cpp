#include "PmergeMe.hpp"

/* ************************************************************************** */
/*                             Canonical Form                                 */
/* ************************************************************************** */

PmergeMe::PmergeMe()
{
	std::runtime_error("Error: No arguments given !");
}

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

PmergeMe::PmergeMe(PmergeMe &cpy)
{
	cpy = *this;
}

PmergeMe& PmergeMe::operator=(PmergeMe &copy)
{
	if (&copy == this)
		return (*this);
	this->tabv = copy.tabv;
	this->tabq = copy.tabq;
	return (*this);
}

/* ************************************************************************** */
/*                             Public functions                               */
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
	else if (*it == '-')
		it++;
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
			std::cout << *it << " ";	
	}
	std::cout << std::endl;
}

bool PmergeMe::is_sorted(std::vector<int> tabv, int begin, int steps)
{
	int max_left = get_max(tabv, begin, begin + steps / 2);
	int max_right = get_max(tabv, begin + (steps / 2), begin + steps);
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
	for (int i = 0; i < size; i += pairs)
	{
		if (i + pairs > size)
			break;
		if (!is_sorted_deque(tab, i, pairs))
			swap_deque(tab, i, pairs);
	}
	ford_johnson_deque(tab, pairs * 2);
	main.insert(main.begin(), tab.begin(), tab.begin() + pairs);

	for (int i = pairs; i < size; i += pairs)
	{
		if (i + (pairs) > size)
		{
			if (i + (pairs / 2) - 1 < size)
				odd.insert(odd.begin(), tab.begin() + pairs + (pairs * main_anum), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2));
			if (tab.size() % (pairs / 2) != 0)
				temp.insert(temp.begin(), tab.end() - (tab.size() % (pairs / 2)) , tab.end());
			break ;
		}
		main.insert(main.begin() + main.size(), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2), tab.begin() + pairs + (pairs * main_anum) + pairs);
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

	if (pend.size() != 0)
	{
		while (pend.size() != 0)
		{
			jacobs_num = get_Jacobsthal(i);
			i++;
			number_of_first_pend = inserted_from_pend + 2;
			b = (((jacobs_num + 1) - (number_of_first_pend)) * (pairs / 2)) - 1;
			comp = b;
			if (comp > (pend.size() - 1))
			{
				b = pend.size() - 1;
				jacobs_num = number_of_first_pend + ((pend.size() / (pairs / 2)));
			}
			pairs_to_insert_in_main = (b + 1) / (pairs / 2);
			for (int i = 0; i < pairs_to_insert_in_main; i++)
			{
				a = (inserted_from_pend + jacobs_num) * (pairs / 2) - 1;
				binary_insertion_deque(main, a, pend, b, pairs);
				b -= (pairs / 2);
				jacobs_num--;
				inserted_from_pend++;
			}
		}
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

	// Base Case
	if (size / (pairs / 2)	 < 2)
		return ;
	
	// Sort the pairs
	for (int i = 0; i < size; i += pairs)
	{
		if (i + pairs > size)
			break;
		if (!is_sorted(tab, i, pairs))
			swap(tab, i, pairs);
	}

	// Recursive call
	ford_johnson_vec(tab, pairs * 2);

	// Insert the first 2 pairs {b1, a1}
	main.insert(main.begin(), tab.begin(), tab.begin() + pairs);

	// Insert the rest of the pairs in the main, pend, odd, temp
	for (int i = pairs; i < size; i += pairs)
	{
		if (i + (pairs) > size)
		{
			// Insert in the odd
			if (i + (pairs / 2) - 1 < size)
				odd.insert(odd.begin(), tab.begin() + pairs + (pairs * main_anum), tab.begin() + pairs + (pairs * main_anum) + (pairs / 2));
			
			// Insert the temp that are not in the pairs
			if (tab.size() % (pairs / 2) != 0)
				temp.insert(temp.begin(), tab.end() - (tab.size() % (pairs / 2)) , tab.end());
			
			break ;
		}
		// Insert in the main
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

	// Insert the pend in the main
	if (pend.size() != 0)
	{
		while (pend.size() != 0)
		{
			jacobs_num = get_Jacobsthal(i);
			i++;
			number_of_first_pend = inserted_from_pend + 2;
			b = (((jacobs_num + 1) - (number_of_first_pend)) * (pairs / 2)) - 1;
			comp = b;
			// Check if the b is greater than the size of the pend when jacobsthal num > idx of last element of the pend
			if (comp > (pend.size() - 1))
			{
				// put the b to the last index of the pend
				b = pend.size() - 1;
				jacobs_num = number_of_first_pend + ((pend.size() / (pairs / 2)));
			}
			pairs_to_insert_in_main = (b + 1) / (pairs / 2);
			for (int i = 0; i < pairs_to_insert_in_main; i++)
			{
				a = (inserted_from_pend + jacobs_num) * (pairs / 2) - 1;
				binary_insertion(main, a, pend, b, pairs);
				b -= (pairs / 2);
				jacobs_num--;
				inserted_from_pend++;
			}
		}
		// Insert the odd in the main
		if (odd.size() != 0)
			binary_insertion(main, (main.size() - 1), odd, odd.size() - 1, pairs);
		// Clear the tab and insert the main into the tab
		tab.erase(tab.begin(), tab.end());
		tab.insert(tab.begin(), main.begin(), main.end());
		// Insert the temp in the tab
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

/* ************************************************************************** */
/*                             Public static functions                        */
/* ************************************************************************** */

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
	
	for (int i = begin; i < begin + (steps / 2); i++)
		tabv[i] = tabv[i + (steps / 2)]; 
	for (int i = begin + (steps / 2); i < begin + steps; i++)
		tabv[i] = temp[i - (begin + (steps / 2))];
}

void	PmergeMe::swap_deque(std::deque<int> &tabv, int begin, int steps)
{
	std::vector<int> temp;
	temp.insert(temp.begin(), tabv.begin() + begin, tabv.begin() + begin + (steps / 2));
	
	for (int i = begin; i < begin + (steps / 2); i++)
		tabv[i] = tabv[i + (steps / 2)]; 
	for (int i = begin + (steps / 2); i < begin + steps; i++)
		tabv[i] = temp[i - (begin + (steps / 2))];
}


void	PmergeMe::binary_insertion(std::vector<int> &tab, int tab_idx, std::vector<int> &element, int idx_element, int pair)
{
	while (tab_idx >= 0 && tab[tab_idx] > element[idx_element])
		tab_idx -= pair / 2;
	if (tab_idx < 0)
		tab.insert(tab.begin(), element.begin() + idx_element - (pair / 2) + 1, element.begin() + idx_element + 1);
	else
		tab.insert(tab.begin() + tab_idx + 1, element.begin() + idx_element - (pair / 2) + 1, element.begin() + idx_element + 1);
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
		tab.insert(tab.begin(), element.begin() + idx_element - (pair / 2) + 1, element.begin() + idx_element + 1);
	else
		tab.insert(tab.begin() + tab_idx + 1, element.begin() + idx_element - (pair / 2) + 1, element.begin() + idx_element + 1);
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
		std::cout << *it << " ";
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
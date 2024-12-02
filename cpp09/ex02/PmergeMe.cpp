#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string* param, int size)
{
	std::vector<int> *step1;
	for (int i = 0; i < size; i++)
		parse_add(param[i]);
	step1 = sort_pair(&this->tabv);
	display(*step1);
	delete step1;
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

void PmergeMe::display(std::vector<int> tab)
{
	for (std::vector<int>::iterator it = tab.begin(); it != tab.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != tab.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}


std::vector<int> *PmergeMe::sort_pair(std::vector<int> *tab)
{
	std::vector<int> *left;
	std::vector<int> *right;
	std::vector<int> left_temp;
	std::vector<int> right_temp;
	std::vector<int> *ret;
	int size = tab->size();

	
	if (size == 2 || size == 3)
	{
		sort2(*tab);
		// std::cout << std::string(50, '*') << "size: " <<  size << std::endl;
		// display(*tab);
		// std::cout << std::string(50, '*') << std::endl;
		return (tab);
	}
	if (size % 2 == 0 && size / 2 % 2 == 1)
	{
		if ((size / 2) - 1 == 2)
		{
			left_temp.insert(left_temp.begin(), tab->begin(), tab->begin() + (size / 2) + 1);
			right_temp.insert(right_temp.begin(), tab->begin() + (size / 2) + 1, tab->end());
		}
		else
		{
			left_temp.insert(left_temp.begin(), tab->begin(), tab->begin() + (size / 2) - 1);
			right_temp.insert(right_temp.begin(), tab->begin() + (size / 2) - 1, tab->end());
		}
	}
	else
	{
		left_temp.insert(left_temp.begin(), tab->begin(), tab->begin() + (size / 2));
		right_temp.insert(right_temp.begin(), tab->begin() + (size / 2), tab->end());
	}
	std::cout << "size: " << size << std::endl;
	std::cout << "temp_left size: " << left_temp.size() << std::endl;
	display(left_temp);
	std::cout << "temp_right size: " << right_temp.size() << std::endl;
	display(right_temp);
	left = sort_pair(&left_temp);
	right = sort_pair(&right_temp);
	std::cout << "size: " << size << std::endl;
	std::cout << "left size: " << left->size() << std::endl;
	display(*left);
	std::cout << "right size: " << right->size() << std::endl;
	display(*right);
	if (get_max(*left, *right) == 0	)
	{
		// std::cout << "right first"<< std::endl;
		ret = new std::vector<int>(right->begin(), right->end());
		ret->insert(ret->begin() + ret->size(), left->begin(), left->end());
	}
	else
	{
		// std::cout << "left first" << std::endl;
		ret = new std::vector<int>(left->begin(), left->end());
		ret->insert(ret->begin() + ret->size(), right->begin(), right->end());
	}
	if (size % 2)
		ret->insert(ret->begin() + ret->size(), tab->back());
	std::cout << "ret :";
	display(*ret);
	if (tab->size() >= 8)
	{
		delete left;
		delete right;
	}
	return (ret);
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
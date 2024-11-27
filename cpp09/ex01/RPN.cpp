#include "RPN.hpp"

RPN::RPN(std::string operation):operation(operation)
{
	try
	{
		parse_input(operation);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void RPN::parse_input(std::string str)
{
	int lst_lim_pos = 0;
	std::string word;
	std::size_t idx;
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		idx = str.find_first_of(' ');
		if (idx == std::string::npos)
			word = str.substr(lst_lim_pos);
		else
		{
			word = str.substr(lst_lim_pos, idx);
		}
		std::cout << idx << "/" << lst_lim_pos << std::endl;
		lst_lim_pos = idx;
		std::cout << word << std::endl;
	}
}

bool RPN::is_number(std::string str)
{
	for (std::string::iterator it = str.begin(); it != str.begin(); it++)
	{
		if (it == str.begin() && *it == '-')
		{
			if (!(*it >= '0' && *it <= '9'))
				return (false);
		}	
	}
	return (true);
}

bool RPN::is_operator(std::string str)
{
	if (!str.compare("+") || !str.compare("-") || !str.compare("/") || !str.compare("*"))
		return (true);
	return false;
}
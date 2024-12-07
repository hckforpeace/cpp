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
	int jumps;
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		idx = str.find_first_of(' ', lst_lim_pos);
		if (idx == std::string::npos)
		{
			word = str.substr(lst_lim_pos);
			reverse_polish(word);
			break ;
		}
		else
		{
			jumps = idx - lst_lim_pos;
			word = str.substr(lst_lim_pos, jumps);
		}
		if (!is_number(word) && !is_operator(word))
			throw std::runtime_error("Error");
		lst_lim_pos = idx + 1;
		reverse_polish(word);
	}
	std::cout << polstack.top() << std::endl;
}

void RPN::reverse_polish(std::string input)
{
	std::stringstream str;
	std::string temp;
	int				first;
	int				second;
	int			res;

	if (polstack.size() == 0 && is_operator(input))
	{
		throw std::runtime_error("Error");
	}
	if (is_operator(input))
	{
		temp = polstack.top();
		polstack.pop();
		if (polstack.size() == 0)
			throw std::runtime_error("Error");
		str << temp;
		str >> first;
		str.clear();
		temp = polstack.top();
		polstack.pop();
		str << temp;
		str >> second;
		res = calculate(first, second, input);
		str.str("");
		str.clear();
		str << res;
		polstack.push(str.str());
		return ;
	}
	polstack.push(input);
}

int	RPN::calculate(int first, int second, std::string a)
{
	if (!a.compare("+"))
		return (second + first);
	else if (!a.compare("-"))
		return (second - first);
	else if (!a.compare("/"))
		return (second / first);
	else
		return (second * first);
}

bool RPN::is_number(std::string str)
{
	int i;
	std::stringstream sstr;
	sstr << str;
	if (!str.compare(""))
		return (false);
	std::string::iterator it = str.begin();
	if (*it == '-')
		it++;
	for (; it != str.end(); it++)
	{
		if (!(*it >= '0' && *it <= '9'))
			return (false);
	}
	sstr >> i;
	if (i > 10)
		throw std::runtime_error("Error: number bigger than 10");
	else if (i < 0)
		throw std::runtime_error("Error: number lesser than 0");
	return (true);
}

bool RPN::is_operator(std::string str)
{
	if (!str.compare(""))
		return (false);
	if (!str.compare("+") || !str.compare("-") || !str.compare("/") || !str.compare("*"))
		return (true);
	return (false);
}
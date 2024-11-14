#include <iostream>

void	display_special_case(std::string f, std::string d);

bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	is_number(std::string s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (!is_digit(s[i]))
			return (false);
	}
	return (true);
}

bool	parse_string(std::string data)
{
	if (data.length() == 1 && is_number(data))
		return (true);
	if (data.find('f') != data.npos)
	{
		if (data.find('f') != (data.length() - 1))
			return (false);
		if (data.find('.') == data.npos || data.find('.') == 0)
			return (false);
		data.erase(data.find('f'), 1);
		data.erase(data.find('.'), 1);
		return (is_number(data));
	}
	if (data.find('.') != data.npos)
	{
		if (data.find('.') == 0)
			return (0);
		data.erase(data.find('.'), 1);
		return (is_number(data));
	}
	return (is_number(data));
}

bool is_special_case(std::string s)
{
	if (!s.compare("-inf") || !s.compare("+inf") || !s.compare("-inff") || !s.compare("+inff") || !s.compare("nan"))
		return (true);
	return (false);
}

void	parse_special_charachter(std::string value)
{
	std::string tab[5] = {"nan", "+inf", "-inf", "-inff", "+inff"};
	for (int i = 0; i < 5; i++)
	{
		if (!value.compare(tab[i]))
		{
			if (i <= 2)
				display_special_case(tab[i] + "f", tab[i]);
			else
			{
				std::string copy(tab[i]);
				display_special_case(tab[i], copy.erase(copy.find('f'), 1));
			}
		}
	}
}

int	get_precision(std::string s)
{
	std::string copy(s);
	
	if (s.find('.') == s.npos)
		return (1);
	else
	{
		std::string sub = s.substr(s.find('.'));
		int sub_len = sub.length();
		if (sub_len == 1)
			return (sub_len);
		else
		{
			for (int j = 1; j < sub_len; j++)
			{
				if (sub[j] != '0' && sub[j] != 'f')
					return (-1);
			}
			return (1);
		}
	}
	return (-1);
}
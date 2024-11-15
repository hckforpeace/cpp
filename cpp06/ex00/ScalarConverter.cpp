#include "ScalarConverter.hpp"

bool	parse_string(std::string data);
int	get_precision(std::string s);
bool is_special_case(std::string s);
void	parse_special_charachter(std::string value);
void	display(int i, unsigned char c, float f, double d, int precision);
void from_float(float f, int precision);
void	from_int(int i, int precision);
void	from_double(double d, int precision);

void	ScalarConverter::convert(std::string value)
{
	if (is_special_case(value))
		parse_special_charachter(value);
	else if (parse_string(value))
	{
		int precision = get_precision(value);
		std::stringstream	type(value); 
		if (value.find('f') != value.npos)
		{
			float f;
			type >> f;
			from_float(f, precision);
		}
		else if (value.find('.') != value.npos)
		{
			double d;
			type >> d;
			from_double(d, precision);
		}
		else
		{
			int i;
			type >> i;
			from_int(i, precision);			
		}
	}
	else
		std::cout << "Error! Wrong input ! ./convert integer, float or double" << std::endl;
}

ScalarConverter::ScalarConverter()
{

}
ScalarConverter::~ScalarConverter()
{

}
ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
	return ;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return (*this);
}

#include <iostream>


void	display(int i, unsigned char c, float f, double d, int precision)
{
	std::cout << "char: ";
	if (c >= 32 && c <= 126)
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: ";
	std::cout << f;
	if (precision == 1)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout << "double: " ;
	std::cout << d;
	if (precision == 1)
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
	
}

void from_float(float f, int precision)
{
	char c= static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);
	display(i, c, f, d, precision);
}
void	from_int(int i, int precision)
{
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	display(i, c, f, d, precision);
}
void	from_double(double d, int precision)
{
	float f = static_cast<float>(d);
	unsigned char c = static_cast<unsigned char>(d);
	int i = static_cast<int>(d);
	display(i, c, f, d, precision);
}


void	display_special_case(std::string f, std::string d)
{
	std::cout << "char: impossible" << std::endl; 
	std::cout << "int: impossible" << std::endl; 
	std::cout << "float: " << f << std::endl; 
	std::cout << "double: " << d << std::endl; 
}


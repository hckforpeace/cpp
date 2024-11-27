// #include <iostream>
// #include <map>
// #include <sstream>
// #include <ctime>
// /* int	main()
// {
// 	std::string str = "2011-02-01 | 3";
// 	// std::stringstream type(s);

// 	// int i;
// 	// type >> i;
// 	// std::cout << i;
// 	std::string date = str.substr(0, str.find(' '));
// 	std::cout << date;
// 	return (0);
// } */

// int	main()
// {
// 	std::string date = "2011-01-03";
// 	std::string str = "%Y-%m-%d";

	
// }

#include <iostream>
#include <map>
#include <string>
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Error: could not open file." << std::endl;
	else
	{
		try
		{
			BitcoinExchange BT(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	// std::cout << "is leap year: " << BitcoinExchange::is_leap_year(2024);
	return (0);
}
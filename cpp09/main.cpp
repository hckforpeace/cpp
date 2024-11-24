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
int	main()
{
	// std::multimap<std::string, std::string> map;

	// std::string line = "10/10/2000,3";
	// int sepIdx = line.find(',');
	// if (line.find(',') == std::string::npos)
	// 	throw std::runtime_error("bas line in db file");
	// std::string date = line.substr(0, sepIdx);
	// std::string value =  line.substr(sepIdx+1);
	// std::cout << "date: " << date << ", value: " << value << std::endl;
	try
	{
		BitcoinExchange BT("hello");
		BT.displayDB();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}
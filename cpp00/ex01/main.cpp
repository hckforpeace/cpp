#include "PhoneBook.hpp"

int	main()
{
	PhoneBook my_book;

	std::string input;
	std::cout << "Commands:" << std::endl;
	std::cout << "\tSEARCH: displays PhoneBook contacts" << std::endl;
	std::cout << "\tADD: lets you add a contact" << std::endl;
	std::cout << "\tEXIT: exits Phonebook" << std::endl << std::endl;
	std::getline(std::cin, input);
	while (input != "EXIT")
	{
		if (input == "SEARCH")	
			my_book.search();
		else if (input == "ADD")
			my_book.add();
		std::getline(std::cin, input);
	}
	return (0);
}
/* 
int	main()
{
	std::string str;

	str = "jpierre";
	std::cout << std::setw(10) << str << std::setfill('.');
	return (0);
} */
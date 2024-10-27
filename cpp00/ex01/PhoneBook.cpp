#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->num_contact = 0;
}

void PhoneBook::add()
{
	std::string name, last_name, nickname, phone_number, darkest_secret;

	std::cout << "Name: ";
	std::getline(std::cin, name);
	if (name.empty())
	{
		std::cout << "field can't be empty\n";
		return ;
	}
	std::cout << "Last Name: ";
	std::getline(std::cin, last_name);
	if (last_name.empty())
	{
		std::cout << "field can't be empty\n";
		return ;
	}
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	if (nickname.empty())
	{
		std::cout << "field can't be empty\n";
		return ;
	}
	std::cout << "Phone Number: ";
	std::getline(std::cin, phone_number);
	if (phone_number.empty())
	{
		std::cout << "field can't be empty\n";
		return ;
	}
	std::cout << "Darkest Secret: ";
	std::cin >> darkest_secret;
	if (darkest_secret.empty())
	{
		std::cout << "field can't be empty\n";
		return ;
	}

	Contact obj1(name, last_name, nickname, phone_number, darkest_secret);
	if (this->num_contact == 8)
		this->contacts[7] = obj1;
	else
	{
		this->contacts[this->num_contact] = obj1;
		this->num_contact++;
	}
}

void	PhoneBook::display()
{
	std::string	name, lastname, nickname;
	int i = 0;
	std::cout << " " << std::string(43, '_') << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << "Index";
	std::cout << "|";
	std::cout << std::setw(10) << "First Name";
	std::cout << "|";
	std::cout << std::setw(10) << "Last Name";
	std::cout << "|";
	std::cout << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;
	while (i < this->num_contact)
	{
		name = contacts[i].get_name();
		lastname = contacts[i].get_lastname();
		nickname = contacts[i].get_nickname();

		if (name.length() >= 10)
			name = name.substr(0, 9) + '.';
		if (lastname.length() >= 10)
			lastname = lastname.substr(0, 9) + '.';
		if (nickname.length() >= 10)
			nickname = nickname.substr(0, 9) + '.';

		std::cout << "|"; 
		std::cout << std::setw(10) << i + 1;
		std::cout << "|";
		std::cout << std::setw(10) << name;
		std::cout << "|";
		std::cout << std::setw(10) << lastname;
		std::cout << "|";
		std::cout << std::setw(10) << nickname;
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << " " << std::string(43, '_') << std::endl << std::endl;
}

void	PhoneBook::search()
{
	int	i;
	if (this->num_contact == 0)
		return ;
	display();
	std::cout << "input an index to get more information about Contact: ";
	std::cin >> i;
	while (i <= 0 || i > this->num_contact)
	{
		if (std::cin.fail())
		{
			std::cout << "wrong format the input most be an integer: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			std::cout << "wrong index please choose an index between 1 and " << this->num_contact << " ";
		std::cin >> i;
	}
	this->contacts[i - 1].display_contact();
}
#include "Contact.hpp"

Contact::Contact(std::string name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->name = name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

void	Contact::display_contact()
{
	std::cout << "Nirst Name: " << this->name << std::endl;
	std::cout << "Last Name: " << this->last_name << std::endl; 
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone Number: " << this->phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->phone_number << std::endl;
}

Contact::Contact()
{
	Contact("", "", "", "", "");
}

std::string	Contact::get_name()
{
	return this->name;
}

std::string	Contact::get_lastname()
{
	return this->last_name;
}

std::string	Contact::get_nickname()
{
	return this->nickname;
}

std::string	Contact::get_phonenumber()
{
	return this->phone_number;
}

std::string	Contact::get_darkestsecret()
{
	return this->darkest_secret;
}
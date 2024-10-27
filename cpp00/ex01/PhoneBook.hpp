#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <limits> 

class PhoneBook
{
	private:
		Contact contacts[8];
		int		num_contact;
		void	display();
	public:
		PhoneBook();
		void search();
		void add();
};

#endif
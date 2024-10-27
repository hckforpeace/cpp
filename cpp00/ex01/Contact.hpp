#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact {

    private:
        std::string name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		Contact(std::string name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
		void		display_contact();
		std::string	get_name();
		std::string	get_lastname();
		std::string	get_nickname();
		std::string	get_phonenumber();
		std::string	get_darkestsecret();

};

#endif
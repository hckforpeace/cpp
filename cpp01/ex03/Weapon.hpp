#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	
	public:
		void				setType(std::string type);
		std::string const&	getType();
		Weapon(std::string type);
	private:
		std::string type;
};



#endif
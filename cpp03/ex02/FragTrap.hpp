#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(FragTrap const &obj);
		FragTrap(std::string _name);
		FragTrap();
		~FragTrap();
		FragTrap& operator=(FragTrap const &obj);
		void highFivesGuys(void);
};

#endif
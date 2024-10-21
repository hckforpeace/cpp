#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(FragTrap const &obj);
		FragTrap(void);
		~FragTrap(void);
		FragTrap(std::string _name);
		FragTrap& operator=(FragTrap const &obj);
		void highFivesGuys(void);
};

#endif
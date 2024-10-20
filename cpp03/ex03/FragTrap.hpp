#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	private:
	public:
		FragTrap(FragTrap const &obj);
		FragTrap(void);
		~FragTrap(void);
		FragTrap(std::string name);
		FragTrap& operator=(FragTrap const &obj);
		void highFivesGuys(void);
};

#endif
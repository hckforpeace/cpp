#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// inherits from ClapTrap
class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap(ScavTrap const &obj);
		ScavTrap(std::string _name);
		ScavTrap(void);
		~ScavTrap(void);
		void	guardGate(void);
		ScavTrap& operator=(ScavTrap const &obj);
		void	attack(const std::string& target);
};

#endif
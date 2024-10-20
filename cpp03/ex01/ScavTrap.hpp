#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// inherits from ClapTrap
class ScavTrap: public ClapTrap
{
	private:

	public:
		ScavTrap(std::string name);
		ScavTrap(void);
		~ScavTrap(void);
		void	guardGate(void);

};

#endif
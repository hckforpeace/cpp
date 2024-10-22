#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap(const DiamondTrap& obj);
		DiamondTrap(std::string _name);
		DiamondTrap(void);
		~DiamondTrap();
		void	attack(const std::string target);
		void	whoAmI();
		void	display();
		DiamondTrap& operator=(const DiamondTrap& obj);
};

#endif
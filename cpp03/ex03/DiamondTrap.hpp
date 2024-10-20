#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{

	private:
		std::string name;
	public:
		DiamondTrap(std::string name);
		void	attack(const std::string target);
		void	whoAmI();
		void	display();

};

#endif
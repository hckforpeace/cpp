#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
	private:
		std::string name;
		int			hitPoints = 10;
		int			energyPoints = 10;
		int			attackDamage = 0;
	public:
		ClapTrap(ClapTrap const &clp);
		~ClapTrap(void);
		ClapTrap(void);
		ClapTrap(std::string name);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		std::string		getName(void) const;
		void			setName(std::string name);
		void			setHitPoints(int points);
		void			setEnergyPoints(int points);
		void			setAttackDamage(int damage);
		ClapTrap&		operator=(ClapTrap const &clp);
};

#endif
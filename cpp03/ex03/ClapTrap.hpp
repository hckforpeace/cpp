#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap{
	protected:
		std::string _name;
		int			_hp;
		int			_ep;
		int			Damage;
	public:
		ClapTrap(ClapTrap const &clp);
		~ClapTrap(void);
		ClapTrap(void);
		ClapTrap(std::string _name);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
 		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		std::string		get_name(void) const;
/*		void			set_name(std::string _name);
		void			setHitPoints(int points);
		void			setEnergyPoints(int points);
		void			setAttackDamage(int damage); */
		ClapTrap&		operator=(ClapTrap const &clp);
};

#endif
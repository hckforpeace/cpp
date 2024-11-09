#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		AMateria	*items[4];
		std::string name;
	public:
		// Canonical Form
		Character();
		Character(std::string name);
		~Character();
		Character(Character const &copy);
		Character& operator=(Character const &copy);

		// Methods
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		static AMateria	*dump[10];
};

#endif
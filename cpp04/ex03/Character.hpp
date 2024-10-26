#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		AMateria	*items[4];
		std::string name;
	public:
		Character();
		Character(std::string name);
		Character(Character const &obj);
		virtual ~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		Character& operator=(Character const &obj);
		static AMateria	*dump[10];
};

#endif
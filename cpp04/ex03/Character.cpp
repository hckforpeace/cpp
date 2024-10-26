#include "Character.hpp"

AMateria *Character::dump[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

Character::~Character()
{
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->items[i])
			delete this->items[i];
	}
}

Character::Character():name("John")
{
	for (int i = 0; i < 4; i++)
		this->items[i] = NULL;
	std::cout << "Charcater Constructor called" << std::endl;
}

Character::Character(std::string name):name(name)
{
	for (int i = 0; i < 4; i++)
		this->items[i] = NULL;
	std::cout << "Charcater Constructor called" << std::endl;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->items[i] == NULL)
		{
			this->items[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	int i = 0;
	if (! (idx >= 0 && idx <= 4))
	{
		std::cout << "index out of bound please choose between 0 and 3" << std::endl;
		return ;
	}
	if (this->items[i])
	{
		std::cout << "Inventory Already full" << std::endl;
		return ;
	}
	while (i < 10 && dump[i])
		i++;
	if (i == 10)
		std::cout << "dump is full some a Materia will be lost for ever";
	i %= 10;
	dump[i] = this->items[idx];
	this->items[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (! (idx >= 0 && idx <= 4))
	{
		std::cout << "index out of bound please choose between 0 and 3" << std::endl;
		return ;
	}
	if (this->items[idx] == NULL)
	{
		std::cout << "No Materia at index " << idx << std::endl;
		return ;
	}
	this->items[idx]->use(target);
}

std::string const & Character::getName() const
{
	return (this->name);
}

Character::Character(Character const &obj):name(obj.getName())
{
	operator=(obj);
}

Character& Character::operator=(Character const &obj)
{
	for (int i = 0; i < 4; i++)
		if (this->items[i])
			delete this->items[i];
	for (int i = 0; i < 4; i++)
		this->items[i] = obj.items[i]->clone();
	return (*this);
}
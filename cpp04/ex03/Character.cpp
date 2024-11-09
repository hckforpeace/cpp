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
	std::cout << "Charcater Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->items[i] = NULL;
}

Character::Character(std::string name):name(name)
{
	std::cout << "Charcater Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->items[i] = NULL;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->items[i] == NULL)
		{
			this->items[i] = m;
			return ;
		}
	}
	std::cout << "!!! Inventory is Full you need to unequip a Materia to add a new one !!!" << std::endl;
}

void Character::unequip(int idx)
{
	int i = 0;
	if (! (idx >= 0 && idx <= 4))
	{
		std::cout << "!!! index out of bound please choose between 0 and 3 !!!" << std::endl;
		return ;
	}
	if (!this->items[idx])
	{
		std::cout << "!!! Nothing to unequip at index " << idx << " !!!" << std::endl;
		return ;
	}
	std::cout << "removing Materia at index " << idx << " from inventory" << std::endl;
	while (i < 10 && dump[i])
		i++;
	if (i == 10)
		std::cout << "!!! dump is full some a Materia will be lost for ever !!";
	i %= 10;
	dump[i] = this->items[idx];
	this->items[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (! (idx >= 0 && idx < 4))
	{
		std::cout << "!!! index out of bound please choose between 0 and 3 !!!" << std::endl;
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

Character::Character(const Character &copy) : name(copy.getName())
{
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (copy.items[i])
            this->items[i] = copy.items[i]->clone();
        else
            this->items[i] = NULL;
    }
}

Character &Character::operator=(const Character &copy)
{
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (this->items[i])
                delete this->items[i];
            if (copy.items[i])
                this->items[i] = copy.items[i]->clone();
            else
                this->items[i] = NULL;
        }
        this->name = copy.getName();
    }
    return *this;
}
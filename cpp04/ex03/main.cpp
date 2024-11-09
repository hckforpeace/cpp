#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}

/* int main()
{
		// my tests
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	// out of bound index
	me->use(-2, *me);
	me->use(10, *me);
	// no material
	me->use(3, *me);
	me->use(2, *me);
	// unequiping
	me->unequip(0);
	me->unequip(1);

	// Operator
	Character* pepo = new Character("pepo");
	Character copy = *pepo;


	// need to delete MAteria that have been dumped
	for (int i = 0; i < 10; i++)
	{
		if (Character::dump[i])
			delete Character::dump[i];
	}

	delete pepo;
	delete me;
	delete src;
} */
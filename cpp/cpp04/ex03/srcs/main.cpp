#include "../includes/ICharacter.hpp"
#include "../includes/IMateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	std::cout << std::endl << "------- first ice -------" << std::endl;
	AMateria* tmp1;
	tmp1 = src->createMateria("ice");
	me->equip(tmp1);

	me->use(0, *bob);

	std::cout << std::endl << "------- second cure -------" << std::endl;

	AMateria *tmp2;
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);

	me->use(1, *bob);

	std::cout << std::endl << "------- third fire -------" << std::endl;

	AMateria *tmp3;
	tmp3 = src->createMateria("fire");
	me->equip(tmp3);

	me->use(2, *bob);

	std::cout << std::endl << "------- third ice -------" << std::endl;

	AMateria *tmp4;
	tmp4 = src->createMateria("ice");
	me->equip(tmp4);

	me->use(2, *bob);
	
	me->unequip(0);
	delete tmp1;

	me->use(0, *bob);


	std::cout << std::endl << "------- first fill ice -------" << std::endl;

	AMateria *tmp5;
	tmp5 = src->createMateria("ice");
	me->equip(tmp5);

	me->use(0, *bob);
	

	std::cout << std::endl << "------- fourth cure -------" << std::endl;

	AMateria *tmp6;
	tmp6 = src->createMateria("cure");
	me->equip(tmp6);

	me->use(4, *bob);


	std::cout << std::endl << "------- fifth full -------" << std::endl;

	AMateria *tmp7;
	tmp7 = src->createMateria("ice");
	me->equip(tmp7);

	me->use(5, *bob);
	me->unequip(5);
	delete tmp7;

	delete bob;
	delete me;
	delete src;
	
	return 0;
}
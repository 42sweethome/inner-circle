#include "../includes/ICharacter.hpp"

Character::Character()
{
	Name = "doyun";
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
	std::cout << "new Character!" << std::endl;
}

Character::Character(const Character& src)
{
	*this = src;
}

Character::Character(std::string const &Name)
{
	this->Name = Name;
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
	std::cout << "new Character!" << std::endl;
}

Character & Character::operator=(const Character& src)
{
	if (this != &src)
	{
		Name = src.getName();
		for (int i = 0; i < 4; i++)
		{
			if (src.materia[i] != NULL)
				materia[i] = src.materia[i];
			else
				materia[i] = NULL;
		}
	}
	std::cout << "new Character!" << std::endl;
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] != NULL)
			delete materia[i];
	}
	std::cout << "delete Character!" << std::endl;
}

std::string const &Character::getName() const
{
	return (Name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] == NULL)
		{
			std::cout << i <<"'s " << m->getType() << " is equiped !" <<std::endl;
			materia[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (materia[idx] && (idx >= 0 && idx <= 3))
	{
		std::cout << idx <<"'s " << materia[idx]->getType() << " is unequiped !" <<std::endl;
		materia[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (materia[idx] && (idx >= 0 && idx <= 3))
		materia[idx]->use(target);
}

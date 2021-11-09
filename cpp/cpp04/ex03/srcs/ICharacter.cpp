#include "../includes/ICharacter.hpp"

Character::Character()
{
	Name = "ddjs";
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;//????NULL 값 들가지나?
}

Character::Character(const Character& src)
{
	*this = src;
}

Character::Character(std::string const &Name)
{
	this->Name = Name;
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
			materia[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		materia[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= 3)
		materia[idx]->use(target);
}

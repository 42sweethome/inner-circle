#include "../includes/IMateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
	std::cout << "new materiaSource!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	*this = src;
	std::cout << "copy materiaSource!" << std::endl;
}

MateriaSource & MateriaSource::operator=(const MateriaSource& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (src.materia[i] != NULL)
				materia[i] = src.materia[i]->clone();
			else
				materia[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] != NULL)
		{
			delete materia[i];
		}
	}
	std::cout << "delete MateriaSource!" << std::endl;
}

void MateriaSource::learnMateria(AMateria *src)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] == NULL)
		{
			materia[i] = src;
			return ;
		}
	}
	delete src;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] && materia[i]->getType() == type)
		{
			return (materia[i]->clone());
		}
	}
	return (0);
}

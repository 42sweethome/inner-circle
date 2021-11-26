#include "../includes/AMateria.hpp"

Cure::Cure()
{
	type = "cure";
	std::cout << "new Cure!" << std::endl;
}

Cure::Cure(const Cure& src) : AMateria (src)
{
	std::cout << "copy Cure!" << std::endl;
}

Cure & Cure::operator=(const Cure& src)
{
	if (this != &src)
	{
		type = src.getType();
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "delete Cure!" << std::endl;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
	AMateria *cure = new Cure();
	return (cure);
}

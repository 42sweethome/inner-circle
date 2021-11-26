#include "../includes/AMateria.hpp"

Ice::Ice()
{
	type = "ice";
	std::cout << "new Ice!" << std::endl;
}

Ice::Ice(const Ice& src) : AMateria (src)
{
	std::cout << "new Ice!" << std::endl;
}

Ice & Ice::operator=(const Ice& src)
{
	if (this != &src)
	{
		type = src.getType();
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "delete Ice!" << std::endl;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const
{
	AMateria *ice = new Ice();
	return (ice);
}

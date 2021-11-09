#include "../includes/AMateria.hpp"

Ice::Ice()
{
	type = "ice";
}

Ice::Ice(const Ice& src)
{
	*this = src;
}

Ice & Ice::operator=(const Ice& src)
{
	if (this != &src)
	{
		type = src.getType();
	}
	std::cout << "new Ice!" << std::endl;
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

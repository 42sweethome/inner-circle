#include "../includes/AMateria.hpp"

AMateria::AMateria()
{

}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria& src)
{
	*this = src;
}

AMateria & AMateria::operator=(const AMateria& src)
{
	if (this != &src)
	{
		type = src.getType();
	}
	std::cout << "new AMateria!" << std::endl;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "delete AMateria!" << std::endl;
}

std::string const &AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << target.getName() << std::endl;
}

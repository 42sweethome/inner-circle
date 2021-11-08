#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	type = "WrongAnimal!";
	std::cout << "WrongAnimal Born!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "WrongAnimal Born!" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Died" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this != &src)
	{
		type = src.type;
	}
	return (*this);
}

std::string WrongAnimal::getType(void) const
{
    return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "haha" << std::endl;
	return ;
}
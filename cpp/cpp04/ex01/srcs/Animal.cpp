#include "../includes/Animal.hpp"

Animal::Animal(void)
{
	type = "Animal!";
	std::cout << "Animal Born!" << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "Animal copy Born!" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal Died" << std::endl;
}

Animal & Animal::operator=(const Animal &src)
{
	if (this != &src)
	{
		type = src.type;
	}
	return (*this);
}

std::string Animal::getType(void) const
{
    return (type);
}

void Animal::addIdea(std::string idea, int i)
{
	idea = "";
	i = 0;
	std::cout << idea << i << std::endl;
}
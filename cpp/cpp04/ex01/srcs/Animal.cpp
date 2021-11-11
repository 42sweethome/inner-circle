#include "../includes/Animal.hpp"

Animal::Animal(void)
{
	type = "Animal!";
	std::cout << "Animal Born!" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy Born!" << std::endl;
	*this = src;
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

std::string Animal::outputIdeas(int i) const
{
	i = 0;
	std::cout << i << std::endl;
	return("");
}

void Animal::dupIdeas(const Animal &animal)
{
	Animal a;
    a = animal;
}
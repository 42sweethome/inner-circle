#include "../includes/Dog.hpp"

Dog::Dog(void)
{
	type = "Dog";
	std::cout << "Dog Born!" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog Born!" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog Died" << std::endl;
}

Dog & Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		type = src.type;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wal Wal" << std::endl;
	return ;
}
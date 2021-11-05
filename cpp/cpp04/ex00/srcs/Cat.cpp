#include "../includes/Cat.hpp"

Cat::Cat(void)
{
	type = "Cat";
	std::cout << "Cat Born!" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat Born!" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat Died" << std::endl;
}

Cat & Cat::operator=(const Cat &src)
{
	if (this != &src)
	{
		type = src.type;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "ya ya" << std::endl;
	return ;
}

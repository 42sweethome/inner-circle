#include "../includes/Cat.hpp"

Cat::Cat(void)
{
	type = "Cat";
	brain = new Brain;
	std::cout << "Cat Born!" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
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
		brain = new Brain;
		brain->copyIdeas(src.brain);
	}
	std::cout << "Cat Born!" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "ya ya" << std::endl;
	return ;
}
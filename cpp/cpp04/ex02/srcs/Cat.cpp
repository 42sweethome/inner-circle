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
	delete brain;
	std::cout << "Cat Died" << std::endl;
}

Cat & Cat::operator=(const Cat &src)
{
	if (this != &src)
	{
		type = src.type;
		brain = new Brain;
		for (int i = 0; i < 100; i++)
			brain->copyIdeas(src.brain->outputIdeas(i), i);
	}
	std::cout << "Cat copy Born!" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "ya ya" << std::endl;
	return ;
}

void Cat::addIdea(std::string idea, int i)
{
    brain->addIdea(idea, i);
}

void Cat::showIdeas() const
{
    brain->showIdeas();
}

std::string Cat::outputIdeas(int i) const
{
    return (brain->outputIdeas(i));
}

void Cat::dupIdeas(const Animal &animal)
{
    brain->dupIdeas(animal);
}
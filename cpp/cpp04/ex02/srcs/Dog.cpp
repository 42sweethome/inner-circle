#include "../includes/Dog.hpp"

Dog::Dog(void)
{
	type = "Dog";
	brain = new Brain;
	std::cout << "Dog Born!" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	*this = src;
	std::cout << "Dog copy Born!" << std::endl;
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Dog Died" << std::endl;
}

Dog & Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		type = src.type;
		brain = new Brain;
		for (int i = 0; i < 100; i++)
			brain->copyIdeas(src.brain->outputIdeas(i), i);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wal Wal" << std::endl;
	return ;
}

void Dog::addIdea(std::string idea, int i)
{
    brain->addIdea(idea, i);
}

void Dog::showIdeas() const
{
    brain->showIdeas();
}

std::string Dog::outputIdeas(int i) const
{
    return (brain->outputIdeas(i));
}
#include "../includes/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "I have a brain!" << std::endl;
}

Brain::Brain(const Brain &src)
{
    *this = src;
}

Brain::~Brain(void)
{
	std::cout << "I lost a brain" << std::endl;
}

Brain & Brain::operator=(const Brain &brain)
{
	if (this != &brain)
	{
        for (int i = 0; i < 100; i++)
            ideas[i] = brain.ideas[i];
	}
    std::cout << "I have a brain!" << std::endl;
	return (*this);
}

void Brain::addIdea(std::string idea, int i)
{
    ideas[i] = idea;
}

void Brain::copyIdeas(std::string idea, int i)
{
    ideas[i] = idea;
}

std::string Brain::outputIdeas(int i) const
{
    return (ideas[i]);
}

void Brain::showIdeas() const
{
    for(int i = 0; i < 100; i++)
        if (ideas[i] != "")
            std::cout << i << " : " << ideas[i] << std::endl;
}
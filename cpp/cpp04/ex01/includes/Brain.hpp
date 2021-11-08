#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain
{
    public:
        Brain();
        Brain(const Brain & src);
        ~Brain();
        Brain & operator=(const Brain &src);

        void addIdea(std::string idea, int i);
        void copyIdeas(const Brain &brain);
        void showIdeas();
    private:
        std::string ideas[100];
};

#endif
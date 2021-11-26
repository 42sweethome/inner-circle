#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain & src);
        ~Brain();
        Brain & operator=(const Brain &src);

        void addIdea(std::string idea, int i);
        void copyIdeas(std::string idea, int i);
        std::string outputIdeas(int i) const;
        void showIdeas() const;
};

#endif
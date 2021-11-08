#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat & src);
        virtual ~Cat();

        Cat & operator=(const Cat &src);

        virtual void makeSound() const;
        void addIdea(std::string idea, int i);
        void showIdeas() const;
        std::string outputIdeas(int i) const;
        void dupIdeas(const Animal &animal);
    private:
        Brain *brain;
};

#endif
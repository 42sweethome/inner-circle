#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal 
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal & src);
        virtual ~Animal();
     	
        Animal & operator=(const Animal &src);

        virtual void makeSound() const = 0;
        std::string getType() const;
        virtual void addIdea(std::string idea, int i) = 0;
        virtual void showIdeas() const = 0;
        virtual std::string outputIdeas(int i) const = 0;
        virtual void dupIdeas(const Animal &animal) = 0;
};

#endif
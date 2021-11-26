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

        std::string getType() const;
        virtual void makeSound() const = 0;
        virtual void addIdea(std::string idea, int i) = 0;
        virtual void showIdeas() const = 0;
};

#endif
# include "../includes/Cat.hpp"
# include "../includes/Dog.hpp"
# include "../includes/WrongCat.hpp"
# include "../includes/Brain.hpp"

int main()
{
    Animal* animal[4];

    animal[0] = new Dog;
    animal[1] = new Cat;
    animal[2] = new Dog;
    animal[3] = new Cat;

    animal[1]->addIdea("aaa", 0);
    animal[1]->addIdea("bbb", 1);
    animal[1]->addIdea("ccc", 2);
    animal[1]->addIdea("ddd", 3);
    animal[1]->showIdeas();
    animal[3]->dupIdeas(*animal[1]);
    animal[3]->showIdeas();
    for (int i = 0; i < 4; i++)
        delete animal[i];
}
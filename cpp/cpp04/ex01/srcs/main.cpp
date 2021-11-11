# include "../includes/Cat.hpp"
# include "../includes/Dog.hpp"
# include "../includes/WrongCat.hpp"
# include "../includes/Brain.hpp"

int main()
{
    Animal* animal[4];

    animal[0] = new Cat;
    animal[1] = new Dog;
    animal[2] = new Cat;
    animal[3] = new Dog;

    animal[1]->addIdea("aaa", 0);
    animal[1]->addIdea("bbb", 1);
    animal[1]->addIdea("ccc", 2);
    animal[1]->addIdea("ddd", 3);

    std::cout << std::endl << "-------------" << std::endl;
    animal[1]->showIdeas();
    std::cout << "-------------" << std::endl;
    animal[3]->dupIdeas(*animal[1]);
    std::cout << std::endl << "-------------" << std::endl;
    animal[3]->showIdeas();
    std::cout << "-------------" << std::endl;

    for (int i = 0; i < 4; i++)
        delete animal[i];
}
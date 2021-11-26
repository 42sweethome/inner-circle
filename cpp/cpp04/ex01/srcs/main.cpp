# include "../includes/Cat.hpp"
# include "../includes/Dog.hpp"
# include "../includes/WrongCat.hpp"
# include "../includes/Brain.hpp"

int main()
{
    Animal* animal[4];

    animal[0] = new Cat;
    animal[1] = new Dog;

    std::cout << std::endl << "-- Default Cat --" << std::endl;
    animal[0]->showIdeas();
    std::cout << "-----------------" << std::endl;

    std::cout << std::endl << "-- Default Dog --" << std::endl;
    animal[1]->showIdeas();
    std::cout << "-----------------" << std::endl;

    animal[0]->addIdea("cat1", 0);
    animal[0]->addIdea("cat2", 1);
    animal[0]->addIdea("cat3", 2);
    animal[0]->addIdea("cat4", 3);

    animal[1]->addIdea("dog1", 0);
    animal[1]->addIdea("dog2", 1);
    animal[1]->addIdea("dog3", 2);
    animal[1]->addIdea("dog4", 3);

    std::cout << std::endl << "-- Added Idea --" << std::endl;
    std::cout << "Cat Idea" << std::endl;
    animal[0]->showIdeas();
    std::cout << "Dog Idea" << std::endl;
    animal[1]->showIdeas();
    std::cout << "-----------------" << std::endl;
    
    animal[2] = new Cat(*dynamic_cast<Cat *>(animal[0]));
    animal[3] = new Dog(*dynamic_cast<Dog *>(animal[1]));
    
    std::cout << std::endl << "-- Copied Idea --" << std::endl;
    std::cout << "Cat Idea" << std::endl;    
    animal[2]->showIdeas();
    std::cout << "Dog Idea" << std::endl;
    animal[3]->showIdeas();
    std::cout << "-----------------" << std::endl;

    animal[0]->addIdea("CAT5", 0);
    animal[0]->addIdea("CAT6", 1);
    animal[0]->addIdea("CAT7", 2);
    animal[0]->addIdea("CAT8", 3);
    animal[1]->addIdea("DOG5", 0);
    animal[1]->addIdea("DOG6", 1);
    animal[1]->addIdea("DOG7", 2);
    animal[1]->addIdea("DOG8", 3);

    std::cout << std::endl << "-- Check Deep --" << std::endl;
    std::cout << "Cat Idea" << std::endl;    
    animal[0]->showIdeas();
    animal[2]->showIdeas();
    std::cout << "Dog Idea" << std::endl;
    animal[1]->showIdeas();
    animal[3]->showIdeas();
    std::cout << "-----------------" << std::endl;


    for (int i = 0; i < 4; i++)
        delete animal[i];
}
# include "../includes/Cat.hpp"
# include "../includes/Dog.hpp"
# include "../includes/WrongCat.hpp"
# include "../includes/Brain.hpp"

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();

delete j;//should not create a leak
delete i;
}
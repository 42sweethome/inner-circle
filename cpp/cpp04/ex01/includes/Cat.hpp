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
    private:
        Brain *brain;
};

#endif
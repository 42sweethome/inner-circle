#include "Zombie.hpp"

Zombie::Zombie()
{
    name = "철수";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void    Zombie::announce(void)
{
    std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is down..." << std::endl;
}
#include "Zombie.hpp"

Zombie::Zombie()
{
    name = "daekim";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void    Zombie::announce(void)
{
    std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string name, int i)
{
    this->name = name + std::to_string(i);
}

Zombie::~Zombie()
{
    std::cout << name << " is down..." << std::endl;
}

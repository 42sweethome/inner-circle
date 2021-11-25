#include "ClapTrap.hpp"

int main()
{
    {
        ClapTrap james("james");

        james.attack("peter");
        james.takeDamage(1000);
        james.beRepaired(100000);
    }
    std::cout << std::endl;
    {
        ClapTrap soldier;

        soldier.attack("james");
        soldier.takeDamage(2000);
        soldier.beRepaired(100);
    }
    std::cout << std::endl;
    {
        ClapTrap manA("manA");
        ClapTrap manB(manA);

        manB.attack("james");
        manB.takeDamage(2000);
        manB.beRepaired(100);
    }

    return (0);
}
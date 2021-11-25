#include "ClapTrap.hpp"

int main()
{
    ClapTrap james("james");
    ClapTrap soldier;

    soldier.attack("james");
    soldier.takeDamage(2000);
    soldier.beRepaired(100);

    james.attack("peter");
    james.takeDamage(1000);
    james.beRepaired(100000);

    return (0);
}
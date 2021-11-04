#include "ClapTrap.hpp"

int main()
{
    ClapTrap james("james");

    james.attack("peter");
    james.takeDamage(10000);
    james.beRepaired(100000);

    return (0);
}
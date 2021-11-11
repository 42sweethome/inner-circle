#include "ClapTrap.hpp"

int main()
{
    ClapTrap james("james");

    james.attack("peter");
    james.takeDamage(1000);
    james.beRepaired(100000);

    return (0);
}
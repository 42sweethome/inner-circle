#include "../includes/FragTrap.hpp"

int main()
{
    FragTrap james("JAMES");

    james.highFiveGuys();
    james.attack("peter");
    james.beRepaired(1);
    james.takeDamage(2);

    return (0);
}
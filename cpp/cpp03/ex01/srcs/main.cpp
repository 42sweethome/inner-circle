#include "../includes/ScavTrap.hpp"

int main()
{
    ScavTrap james("JAMES");

    james.guardGate();
    james.attack("peter");
    james.beRepaired(1);
    james.takeDamage(2);

    return (0);
}
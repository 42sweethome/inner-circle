#include "../includes/DiamondTrap.hpp"

int main()
{
    DiamondTrap james("JAMES");


    james.attack("peter");
    james.beRepaired(1);
    james.takeDamage(2);

    james.highFiveGuys();
    james.guardGate();

    james.whoAmI();

    return (0);
}
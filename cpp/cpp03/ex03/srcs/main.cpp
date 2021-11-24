#include "../includes/DiamondTrap.hpp"

int main()
{
    {
    DiamondTrap james("JAMES");

    james.attack("peter");
    james.beRepaired(100);
    james.takeDamage(200);

    james.highFiveGuys();
    james.guardGate();

    james.whoAmI();
    }
    return (0);
}
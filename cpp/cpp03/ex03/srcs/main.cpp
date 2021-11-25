#include "../includes/DiamondTrap.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << "**  NONAME  **" <<std::endl;
    std::cout << std::endl;
    {
        DiamondTrap yesi;
        std::cout << std::endl;
        yesi.attack("peter");
        yesi.beRepaired(100);
        yesi.takeDamage(200);

        yesi.highFiveGuys();
        yesi.guardGate();
        yesi.whoAmI();
    }
    std::cout << std::endl;
    std::cout << "**    STRING  **" <<std::endl;
    std::cout << std::endl;
    {
        DiamondTrap harry("harry");
        std::cout << std::endl;
        harry.attack("james");
        harry.beRepaired(100);
        harry.takeDamage(200);

        harry.highFiveGuys();
        harry.guardGate();
        harry.whoAmI();
    }
    std::cout << std::endl;
    std::cout << "**    COPY    **" <<std::endl;
    std::cout << std::endl;
    {
        DiamondTrap james("james");
        std::cout << std::endl;
        DiamondTrap peter(james);
        std::cout << std::endl;

        peter.attack("peter");
        peter.beRepaired(100);
        peter.takeDamage(200);

        peter.highFiveGuys();
        peter.guardGate();
        peter.whoAmI();
    }
    return (0);
}
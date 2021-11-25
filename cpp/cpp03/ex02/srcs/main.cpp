#include "../includes/FragTrap.hpp"

int main()
{
	{	
		ClapTrap soldier("sonkang");
		
		soldier.attack("peter");
		soldier.beRepaired(1);
		soldier.takeDamage(2);
	}
    std::cout << std::endl;
	{
		FragTrap james("JAMES");

		james.highFiveGuys();
		james.attack("peter");
		james.beRepaired(1);
		james.takeDamage(2);
	}
    std::cout << std::endl;
    {
        FragTrap soldier;

		soldier.highFiveGuys();
        soldier.attack("james");
        soldier.takeDamage(2000);
        soldier.beRepaired(100);
    }
    std::cout << std::endl;
    {
        FragTrap manA("manA");
        FragTrap manB(manA);

		manB.highFiveGuys();
        manB.attack("james");
        manB.takeDamage(2000);
        manB.beRepaired(100);
    }

	return (0);
}
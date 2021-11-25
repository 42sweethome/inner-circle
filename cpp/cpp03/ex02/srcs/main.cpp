#include "../includes/FragTrap.hpp"

int main()
{
	{	
		ClapTrap soldier("sonkang");
		
		soldier.attack("peter");
		soldier.beRepaired(1);
		soldier.takeDamage(2);
	}
	{
		FragTrap james("JAMES");

        james.highFiveGuys();
		james.attack("peter");
		james.beRepaired(1);
		james.takeDamage(2);
	}
	return (0);
}
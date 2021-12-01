#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void)
{
    Name = "noname";
   Hitpoints = 100;
   EnergyPoints = 100;
   AttackDamage = 30;
   std::cout << "FragTrap <" << Name << "> is called !"<< std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
   Hitpoints = 100;
   EnergyPoints = 100;
   AttackDamage = 30;
   std::cout << "FragTrap <" << Name << "> is called !"<< std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap &src)
{
	if (this != &src)
	{
		Name = src.Name;
      Hitpoints = src.Hitpoints;
      EnergyPoints = src.EnergyPoints;
      AttackDamage = src.AttackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
   std::cout << "FragTrap <" << Name << "> is uncalled !"<< std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	*this = src;
   std::cout << "FragTrap <" << Name << "> is copy called !"<< std::endl;
}

void FragTrap::highFiveGuys()
{
    std::cout << "FragTrap <" << Name << "> HighFive !!"<< std::endl;
}

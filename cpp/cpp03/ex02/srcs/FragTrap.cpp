#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void)
{
    Name = "noname";
   Hitpoints = 100;
   Energy_points = 100;
   Attack_damage = 30;
   std::cout << "FragTrap <" << Name << "> is called !"<< std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
   Hitpoints = 100;
   Energy_points = 100;
   Attack_damage = 30;
   std::cout << "FragTrap <" << Name << "> is called !"<< std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap &src)
{
	if (this != &src)
	{
		Name = src.Name;
      Hitpoints = src.Hitpoints;
      Energy_points = src.Energy_points;
      Attack_damage = src.Attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
   std::cout << "FragTrap is uncalled !"<< std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	*this = src;
}

void FragTrap::highFiveGuys()
{
    std::cout << "FragTrap " << "HighFive !!"<< std::endl;
}
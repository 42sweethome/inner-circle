#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void)
{
   Name = "noname";
   Hitpoints = 100;
   Attack_damage = 30;
   std::cout << "FragTrap <" << Name << "> is called !"<< std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
   Hitpoints = 100;
   Attack_damage = 30;
   std::cout << "FragTrap <" << Name << "> is called !"<< std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap &src)
{
	if (this != &src)
	{
		Name = src.Name;
      Hitpoints = src.Hitpoints;
      Attack_damage = src.Attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
   std::cout << "FragTrap <" << Name  << "> is uncalled !"<< std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	*this = src;
   std::cout << "FragTrap <" << Name << "> is copy called !"<< std::endl;
}

void FragTrap::highFiveGuys()
{
    std::cout << "FragTrap <" << Name  << "> HighFive !!"<< std::endl;
}
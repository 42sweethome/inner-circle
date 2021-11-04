#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
   Hitpoints = 100;
   Energy_points = 100;
   Attack_damage = 30;
   std::cout << "FragTrap <" << Name << "> is called !"<< std::endl;
}

FragTrap::~FragTrap()
{
   std::cout << "FragTrap is uncalled !"<< std::endl;
}

void FragTrap::highFiveGuys()
{
    std::cout << "HighFive !!"<< std::endl;
}
#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{ 
    Hitpoints = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap <" << Name << "> is called !"<< std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap is uncalled !"<< std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is in guardGate mode !"<< std::endl;
}
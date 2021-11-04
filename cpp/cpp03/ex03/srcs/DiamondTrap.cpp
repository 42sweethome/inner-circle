#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) 
{
    this->Name = name;
    ClapTrap::Name = name + "_clap_name";
    Hitpoints = FragTrap::Hitpoints;
    Energy_points = ScavTrap::Energy_points;
    Attack_damage = FragTrap::Attack_damage;
    std::cout << "DiamondTrap <" << Name << "> is called !"<< std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap <" << Name << "> is uncalled !"<< std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name is <" << Name << ">"<< std::endl;
    std::cout << "ClapTrap name is <" << ClapTrap::Name << ">"<< std::endl;
}
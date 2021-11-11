#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    Name = "noname";
    Hitpoints = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap <" << Name << "> is called !"<< std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{ 
    Hitpoints = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap <" << Name << "> is called !"<< std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &src)
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

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap <" << Name << "> is uncalled !"<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	*this = src;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap <" << Name << "> is in guardGate mode !"<< std::endl;
}